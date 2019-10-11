/*
** EPITECH PROJECT, 2018
** stockModule.cpp
** File description:
** src/stock/stockModule.cpp
*/

#include "stockModule.hpp"

StockModule::StockModule(long replenishTime)
{
    _replenishTime = replenishTime;

    for (int i = 0; i < static_cast<int>(I_END); i += 1)
        _stock.push_back(5);
}

StockModule::~StockModule()
{
}

bool StockModule::tryStock(IPizzaModule *pizza)
{
    std::unique_lock<std::mutex> lock(_mtx);
    bool returnValue = false;
    if (pizza->isThereEnoughIngr(_stock)) {
        std::vector<int> ingrNeeded = pizza->getIngrNeeded();
        for (size_t i = 0; i != _stock.size(); i += 1)
            _stock[i] -= ingrNeeded[i];
        returnValue = true;;
    }
    lock.unlock();
    return returnValue;
}

std::vector<int> StockModule::getStock()
{
    std::vector<int> tmp;

    std::unique_lock<std::mutex> lock(_mtx);
    tmp = _stock;
    lock.unlock();
    return tmp;
}

void StockModule::replenish()
{
    std::unique_lock<std::mutex> lock(_mtx);
    for (size_t i = 0; i < _stock.size(); i += 1)
        _stock[i] += 1;
    lock.unlock();
}

void StockModule::waitingForDeliveryTruck()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(_replenishTime));
}

void StockModule::run()
{
    while (1) {
        waitingForDeliveryTruck();
        replenish();
    }
}