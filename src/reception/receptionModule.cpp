/*
** EPITECH PROJECT, 2018
** receptionModule.cpp
** File description:
** src/reception/receptionModule.cpp
*/

#include <ctime>
#include <iostream>
#include "main.hpp"
#include "macro.hpp"
#include "receptionModule.hpp"

typedef void (ReceptionModule::*methodPtr)(const Command &command);

ReceptionModule::ReceptionModule(int ac, char **av)
: Server(3000)
{
    if (ac != 4 || !isFloat(av[1]) || !isInt(av[2]) || !isFloat(av[3]))
        exitPizzeria();
    _multiplier = atof(av[1]);
    _cookNbr = atoi(av[2]);
    _replaceTime = atol(av[3]);
    _open = true;
    _prevKitchenId = 0;
    std::cout << _multiplier << " " << _cookNbr << " " << _replaceTime << std::endl;
}

ReceptionModule::~ReceptionModule()
{
}

void ReceptionModule::openPizzeria()
{
    std::cout << "Pizzeria is now open !" << std::endl;
}

bool ReceptionModule::checkOrder(std::string order)
{
    std::vector<std::string> orderArgs;
    std::stringstream ss(order);
    std::string token;

    while (std::getline(ss, token, ' '))
        if (!token.empty())
            orderArgs.push_back(token);
    for (size_t i = 0; i < orderArgs.size(); i += 1)
        std::cout << "Arg[" << i << "] = " << orderArgs[i] << std::endl;
    return (true);
}

void ReceptionModule::processOrder(const std::vector< std::pair <PizzaType_e, PizzaSize_e> > &order)
{
    (void)order;
    std::cout << "need to process client's order" << std::endl;
}

void ReceptionModule::listenOrder(void)
{
    std::string line;
    std::vector< std::pair <PizzaType_e, PizzaSize_e> > orders;

    std::getline(std::cin, line);
    if (std::cin.eof()) {
        _open = false;
        return;
    }
    if (line.empty() == true)
        return;
    if (line.compare("status") == 0) {
        std::cout << RED "Printing Kitchens status." RST << std::endl;
        askKitchenStatus();
        return;
    }
    orders = organizeClientOrder(line);
    if (orders.size() == 0)
        std::cout << RED "figlio di puttana..." RST << std::endl;
    else {
        std::cout << GRN "Order valid, process..." RST << std::endl;
        sendOrderToKitchen(orders);
    }
}

void ReceptionModule::interactiveShell()
{
    Command command;

    while (_open) {
        waitActivity();
        if (FD_ISSET(0, &_readableClients)) {
            listenOrder();
        } else {
            command = getActivity();
            listenKitchen(command);
        }
    }
    for (auto &e: _register)
        *_clients[e.getPhoneNumber()] << "900 close down\n";
}

void ReceptionModule::updateLog(std::string hallo)
{
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::ofstream log("logfile.txt", std::ios_base::app | std::ios_base::out);

    log << hallo << " " << std::ctime(&end_time);
}

void ReceptionModule::listenKitchen(const Command &command)
{
    if (command._command == "CONNECTION") {
        addKitchenToRegister(command._fd);
    } else if (command._command == "DISCONNECTION") {
        disconnect(command._fd);
        removeKitchenFromRegister(command._fd);
    } else if (command._command == "PIZZADONE") {
        updateKitchenInRegister(command._fd, -1);
        updateLog(command._data);
        std::cout << "Pizzeria[" << command._fd << "]: Pizza done (";
        std::cout << command._data << ")" << std::endl;
    }
}

void ReceptionModule::hireReceptionist(void)
{
    Server::init(200);
    FD_SET(0, &_activeClients);
}

int ReceptionModule::recoverPizzasNumber(std::string str)
{
    int nbr = -1;
    std::string tmp = str;

    if (tmp[0] != 'x')
        return nbr;
    tmp = tmp.substr(1);
    if (!isInt(tmp))
        return nbr;
    nbr = atoi(tmp.c_str());
    if (nbr < 1)
        return -1;
    return nbr;
}

PizzaType_e ReceptionModule::recoverPizzaType(std::string str)
{
    for (size_t i = 0; i < pizzaTypeList.size(); i += 1) {
        if (str == pizzaTypeList[i].first)
            return pizzaTypeList[i].second;
    }
    return END_TYPE;
}

PizzaSize_e ReceptionModule::recoverPizzaSize(std::string str)
{
    for (size_t i = 0; i < pizzaSizeList.size(); i += 1) {
        if (str == pizzaSizeList[i].first)
            return pizzaSizeList[i].second;
    }
    return END_SIZE;
}

std::vector< std::pair <PizzaType_e, PizzaSize_e> > ReceptionModule::organizeClientOrder(std::string order)
{
    std::vector< std::pair <PizzaType_e, PizzaSize_e> > orderNote;
    std::vector<std::string> allCommandsArray = semiliconArray(order);
    std::vector<std::string> commandArray;
    PizzaSize_e size;
    PizzaType_e type;
    int pizzaNbr;

    for (size_t i = 0; i < allCommandsArray.size(); i += 1) {
        commandArray = wordArray(allCommandsArray[i]);
        if (commandArray.size() != 3)
            continue;
        type = recoverPizzaType(commandArray[0]);
        size = recoverPizzaSize(commandArray[1]);
        pizzaNbr = recoverPizzasNumber(commandArray[2]);
        if (type == END_TYPE || size == END_SIZE || pizzaNbr == -1)
            continue;
        for (int u = 0; u < pizzaNbr; u += 1)
            orderNote.push_back({type, size});
    }
    return orderNote;
}

void ReceptionModule::createKitchen(float multiplier, int cookNbr, long replaceTime)
{
    if (fork() == 0) {
        KitchenModule kitchen(multiplier, cookNbr, replaceTime, _prevKitchenId);
        _prevKitchenId += 1;
        kitchen.TurnOnTheStovesAndPreheatTheOvens();
        exit(0);
    } else {
        Client *client = new Client;

        client->getAccepted(_fd);
        _clients[client->getFd()] = client;
        FD_SET(client->getFd(), &_activeClients);
        addKitchenToRegister(client->getFd());
    }
}

void ReceptionModule::addKitchenToRegister(const int &kitchenPhoneNumber) noexcept
{
    _register.push_back(KitchenInfo(kitchenPhoneNumber));
}

void ReceptionModule::removeKitchenFromRegister(const int &kitchenPhoneNumber) noexcept
{
    auto it = _register.begin();
    
    while (it->getPhoneNumber() != kitchenPhoneNumber && it != _register.end())
        it++;
    _register.erase(it);
}

void ReceptionModule::updateKitchenInRegister(const int &kitchen, int offset)
{
    auto it = _register.begin();
    
    while (it->getPhoneNumber() != kitchen && it != _register.end())
        it++;
    it->setCurrentOrders(it->getCurrentOrders() + offset);
}

void ReceptionModule::sendPizzaToKitchen(std::pair <PizzaType_e, PizzaSize_e> order, int fd)
{
    std::string kitchenOrder = "700 ";

    for (size_t i = 0; i != pizzaTypeList.size(); i += 1) {
        if (pizzaTypeList[i].second == order.first) {
            kitchenOrder += pizzaTypeList[i].first + " ";
            break;
        }
    }
    for (size_t i = 0; i != pizzaSizeList.size(); i += 1) {
        if (pizzaSizeList[i].second == order.second) {
            kitchenOrder += pizzaSizeList[i].first;
            break;
        }
    }
    *_clients[fd] << kitchenOrder + "\n";
}

bool sortPair(std::pair<size_t, int> a, std::pair<size_t, int> b)
{
    return a < b;
}

void ReceptionModule::sendOrderToKitchen(std::vector< std::pair <PizzaType_e, PizzaSize_e> > orders)
{
    std::vector< std::pair<size_t, int> > currentOrders;

    for (size_t i = 0; i < orders.size(); i += 1) {
        for (size_t u = 0; u < _register.size(); u += 1)
            currentOrders.push_back({_register[u].getCurrentOrders(), _register[u].getPhoneNumber()});
        std::sort(currentOrders.begin(), currentOrders.end(), sortPair);
        if (currentOrders.empty() || currentOrders[0].first == (size_t)_cookNbr * 2) {
            createKitchen(_multiplier, _cookNbr, _replaceTime);
            sendPizzaToKitchen(orders[i], _register[_register.size() - 1].getPhoneNumber());
            _register[_register.size() - 1].setCurrentOrders(_register[_register.size() - 1].getCurrentOrders() + 1);
        } else {
            sendPizzaToKitchen(orders[i], currentOrders[0].second);
            for (size_t c = 0; c < _register.size(); c += 1) {
                if (currentOrders[0].second == _register[c].getPhoneNumber()) {
                    _register[c].setCurrentOrders(_register[c].getCurrentOrders() + 1);
                    break;
                }
            }
        }
        currentOrders.clear();
    }
}

void ReceptionModule::askKitchenStatus()
{
    std::ofstream myfile;

    myfile.open("graphical.log");
    myfile.close();
    for (auto &e: _register)
        *_clients[e.getPhoneNumber()] << "600 status\n";
}

void ReceptionModule::getPizzeriaStatus(void)
{
    std::ofstream myfile;

    myfile.open("graphical.log");
    myfile.close();
    for (auto &e: _register)
        *_clients[e.getPhoneNumber()] << "601 log status\n";
}