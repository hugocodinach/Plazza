/*
** EPITECH PROJECT, 2018
** kitchenModule.cpp
** File description:
** src/kitchen/kitchenModule.cpp
*/

#include "IpizzaModule.hpp"
#include "main.hpp"
#include "kitchenModule.hpp"
#include "pizzaioloName.hpp"
#include "macro.hpp"

static const char *codeTab[] = {CODE_600, CODE_700, CODE_900, CODE_601, NULL};

KitchenModule::KitchenModule(float multiplier, int cookNbr, long replaceTime, int kitchenId)
: Client(3000, "127.0.0.1"),
_ingredientStock(new StockModule(replaceTime)), _lifeTime(5)
{
    std::cout << BLU "Benvenuto a la Piazza Papa" RST << std::endl;
    _multiplier = multiplier;
    _cookNbr = cookNbr;
    _pizzaQueue = new PizzaQueue();
    _pizzaDoneQueue = new PizzaQueue();
    Client::connect();
    for (size_t i = 0; i != (size_t)_cookNbr; i += 1)
        _cooks.push_back(CookModule(_ingredientStock, _fd, _pizzaQueue, _pizzaDoneQueue, _multiplier, i));
    _threadPool.run(_cooks);
    _kitchenId = kitchenId;
}

KitchenModule::~KitchenModule()
{
}

void KitchenModule::checkPizzaDone()
{
    IPizzaModule *pizza;
    Socket reception;

    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        pizza = _pizzaDoneQueue->pop();
        reception.setFd(_fd);
        reception << std::to_string(_fd) + " PIZZADONE " + pizza->pack() + "\n";
        delete pizza;
    }
}

void KitchenModule::handleDismissal()
{
    bool allWaiting;
    float waitingDuration;

    while (1) {
        allWaiting = true;
        for (size_t i = 0; allWaiting && i != _cooks.size(); i += 1) {
            if (_cooks[i].getStatus() != "Waiting for a pizza")
                allWaiting = false;
        }
        if (allWaiting) {
            waitingDuration = _lifeTime.getElapsedTime();
            if (waitingDuration >= 5) {
                std::cout << RED "Cook[" << _fd <<"]: PASTA LA VISTA !" RST << std::endl;
                close(_fd);
                exit(0);
            }
        } else
            _lifeTime.reset();
    }
}

void KitchenModule::createAnOrderPostItForTheCook(std::string command)
{
    void (KitchenModule::*ptr[])(std::string command) = {
        &KitchenModule::sendKitchenStatus,
        &KitchenModule::sendNewOrderToCooks,
        &KitchenModule::closeDownKitchen
    };

    for (size_t i = 0; codeTab[i]; i += 1) {
        if (strncmp(command.c_str(), codeTab[i], strlen(codeTab[i])) == 0) {
            (this->*ptr[i])(command);
            return;
        }
    }
}

void KitchenModule::logKitchenStatus(std::string command)
{
    std::stringstream formated_statu;
    std::ofstream grahicalLog;

    (void)command;
    formated_statu << "[" << _fd << "]:{";
    for (size_t i = 0; i != _cooks.size(); i += 1) {
        formated_statu << "(" << i + 1 << "," << _cooks[i].getStatus() << ")";
        if ((i + 1) != _cooks.size())
            formated_statu << ",";
    }
    formated_statu << "}.";
    grahicalLog.open ("graphical.log", std::ios::app);
    grahicalLog << formated_statu.str() << std::endl;
    grahicalLog.close();
}

void KitchenModule::sendKitchenStatus(std::string command)
{
    (void)command;
    std::stringstream formated_statu;
    std::ofstream grahicalLog;

    std::string buffer("---------------Kitchen n°" + std::to_string(_fd) + " status---------------\n");
    formated_statu << "[" << _fd << "]:{";
    for (size_t i = 0; i != _cooks.size(); i += 1) {
        buffer.append("\t-Cook n°" + std::to_string(i + 1) + ": " + _cooks[i].getStatus() + "\n");
        formated_statu << "(" << i + 1 << "," << _cooks[i].getStatus() << ")";
        if ((i + 1) != _cooks.size())
            formated_statu << ",";
    }
    formated_statu << "}.";
    grahicalLog.open ("graphical.log", std::ios::app);
    grahicalLog << formated_statu.str() << std::endl;
    grahicalLog.close();
    buffer.append("---------------------------------------------");
    printf("%s\n", buffer.c_str());
}

IPizzaModule *KitchenModule::unpack(std::string pizza)
{
    std::vector<std::string> commandArray = wordArray(pizza);
    IPizzaModule *(*ptr[])(PizzaSize_e size) = {&createAmericana, &createFantasia, &createMargarita, &createRegina, NULL};
    std::string strTab[] = {"americana", "fantasia", "margarita", "regina", ""};
    IPizzaModule *newPizza = NULL;

    for (size_t i = 0; !newPizza && ptr[i]; i += 1) {
        if (strTab[i] == std::string(commandArray[1])) {
            for (size_t u = 0; !newPizza && u != pizzaSizeList.size(); u += 1) {
                if (commandArray[2] == pizzaSizeList[u].first)
                    newPizza = (ptr[i])(pizzaSizeList[u].second);
            }
        }
    }
    return newPizza;
}

void KitchenModule::sendNewOrderToCooks(std::string command)
{
    IPizzaModule *newPizza = unpack(command);
    std::string tmp = command;
    
    tmp.erase(tmp.end() - 1);
    if (newPizza) {
        std::cout << MAG "MARIO, UNA " + tmp + " PER LA QUATTRO !" RST << std::endl;
        _pizzaQueue->push(newPizza);
    }
}

void KitchenModule::closeDownKitchen(std::string command)
{
    (void)command;
    std::cout << RED "PASTA LA VISTA !" RST << std::endl;
    exit(0);
}

void KitchenModule::TurnOnTheStovesAndPreheatTheOvens()
{
    FILE * fp = fdopen(_fd, "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    std::thread stockThread([this]() { _ingredientStock->run(); });
    std::thread dismissalThread([this]() { handleDismissal(); });
    std::thread checkDoneThread([this]() { checkPizzaDone(); });

    if (!fp)
        return;
    while (1) {
        read = getline(&line, &len, fp);
        if (!(read > 0))
            return;
        createAnOrderPostItForTheCook(line);
    }
}