/*
** EPITECH PROJECT, 2018
** americanaModule.cpp
** File description:
** src/pizzas/americanaModule.cpp
*/

#include "americanaModule.hpp"

AmericanaModule::AmericanaModule(PizzaSize_e size)
{
    _size = size;
}

AmericanaModule::~AmericanaModule()
{
}

PizzaType_e AmericanaModule::getPizzaType()
{
    return Americana;
}

PizzaSize_e AmericanaModule::getPizzaSize()
{
    return _size;
}

int AmericanaModule::getCookingTime()
{
    return 2;
}

std::string AmericanaModule::pack()
{
    std::string size;

    for (size_t i = 0; i != pizzaSizeList.size(); i += 1) {
        if (_size == pizzaSizeList[i].second) {
            size = pizzaSizeList[i].first;
        }
    }

    return "americana " + size;
}

bool AmericanaModule::isThereEnoughIngr(std::vector<int> stock)
{
    std::vector<int> ingrNeeded = {1, 1, 1, 0, 0, 1, 0, 0, 0};

    for (size_t i = 0; i != stock.size(); i += 1) {
        if (stock[i] < ingrNeeded[i])
            return false;
    }
    return true;
}

std::vector<int> AmericanaModule::getIngrNeeded()
{
    return {1, 1, 1, 0, 0, 1, 0, 0, 0};
}