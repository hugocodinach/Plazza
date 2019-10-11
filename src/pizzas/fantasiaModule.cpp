/*
** EPITECH PROJECT, 2018
** fantasiaModule.cpp
** File description:
** src/pizzas/fantasiaModule.cpp
*/

#include "fantasiaModule.hpp"

FantasiaModule::FantasiaModule(PizzaSize_e size)
{
    _size = size;
}

FantasiaModule::~FantasiaModule()
{
}

PizzaType_e FantasiaModule::getPizzaType()
{
    return Fantasia;
}

PizzaSize_e FantasiaModule::getPizzaSize()
{
    return _size;
}

int FantasiaModule::getCookingTime()
{
    return 4;
}

std::string FantasiaModule::pack()
{
    std::string size;

    for (size_t i = 0; i != pizzaSizeList.size(); i += 1) {
        if (_size == pizzaSizeList[i].second) {
            size = pizzaSizeList[i].first;
        }
    }

    return "fantasia " + size;
}

bool FantasiaModule::isThereEnoughIngr(std::vector<int> stock)
{
    std::vector<int> ingrNeeded = {1, 1, 0, 1, 0, 0, 1, 0, 1};

    for (size_t i = 0; i != stock.size(); i += 1) {
        if (stock[i] < ingrNeeded[i])
            return false;
    }
    return true;
}

std::vector<int> FantasiaModule::getIngrNeeded()
{
    return {1, 1, 0, 1, 0, 0, 1, 0, 1};
}