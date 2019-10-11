/*
** EPITECH PROJECT, 2018
** cookModule.cpp
** File description:
** src/cook/cookModule.cpp
*/

#include "cookModule.hpp"

CookModule::CookModule(StockModule *stock, int fd, PizzaQueue *queue, PizzaQueue *pizzaDoneQueue, float multiplier, int id)
{
    _stock = stock;
    _queue = queue;
    _doneQueue = pizzaDoneQueue;
    _fd = fd;
    _multiplier = multiplier;
    _id = id;
}

CookModule::~CookModule()
{
}

void CookModule::washHandsThenPutOnGlovesToStartWork(void)
{
    while (1)
        waitForOrder();
}

void CookModule::waitForOrder(void)
{
    IPizzaModule *pizza;

    _status = "Waiting for a pizza";
    pizza = _queue->pop();
    _status = "Taking a pizza";
    waitForIngr(pizza);
}

void CookModule::waitForIngr(IPizzaModule *pizza)
{
    std::vector<int> tmp;
    std::vector<int> ingrNeeded = pizza->getIngrNeeded();

    _status = "Waiting for Ingredients";
    while (!_stock->tryStock(pizza));
    doPizza(pizza);
}

void CookModule::doPizza(IPizzaModule *pizza)
{
    _status = "Cooking";
    std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>((static_cast<float>(pizza->getCookingTime()) * _multiplier))));
    _doneQueue->push(pizza);
}

std::string CookModule::getStatus(void)
{
    return _status;
}