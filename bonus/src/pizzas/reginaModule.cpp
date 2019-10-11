/*
** EPITECH PROJECT, 2018
** reginaModule.cpp
** File description:
** src/pizzas/reginaModule.cpp
*/

#include "reginaModule.hpp"

ReginaModule::ReginaModule(PizzaSize_e size)
{
    _size = size;
}

ReginaModule::~ReginaModule()
{
}

PizzaType_e ReginaModule::getPizzaType()
{
    return Regina;
}

PizzaSize_e ReginaModule::getPizzaSize()
{
    return _size;
}

int ReginaModule::getCookingTime()
{
    return 2;
}

std::string ReginaModule::pack()
{
    std::string size;

    for (size_t i = 0; i != pizzaSizeList.size(); i += 1) {
        if (_size == pizzaSizeList[i].second) {
            size = pizzaSizeList[i].first;
        }
    }

    return "regina " + size;
}

bool ReginaModule::isThereEnoughIngr(std::vector<int> stock)
{
    std::vector<int> ingrNeeded = {1, 1, 1, 0, 1, 0, 0, 1, 0};

    for (size_t i = 0; i != stock.size(); i += 1) {
        if (stock[i] < ingrNeeded[i])
            return false;
    }
    return true;
}

std::vector<int> ReginaModule::getIngrNeeded()
{
    return {1, 1, 1, 0, 1, 0, 0, 1, 0};
}