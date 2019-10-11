/*
** EPITECH PROJECT, 2018
** margaritaModule.cpp
** File description:
** src/pizzas/margaritaModule.cpp
*/

#include "margaritaModule.hpp"

MargaritaModule::MargaritaModule(PizzaSize_e size)
{
    _size = size;
}

MargaritaModule::~MargaritaModule()
{
}

PizzaType_e MargaritaModule::getPizzaType()
{
    return Margarita;
}

PizzaSize_e MargaritaModule::getPizzaSize()
{
    return _size;
}

int MargaritaModule::getCookingTime()
{
    return 1;
}

std::string MargaritaModule::pack()
{
    std::string size;

    for (size_t i = 0; i != pizzaSizeList.size(); i += 1) {
        if (_size == pizzaSizeList[i].second) {
            size = pizzaSizeList[i].first;
        }
    }

    return "margarita " + size;
}

bool MargaritaModule::isThereEnoughIngr(std::vector<int> stock)
{
    std::vector<int> ingrNeeded = {1, 1, 1, 0, 0, 0, 0, 0, 0};

    for (size_t i = 0; i != stock.size(); i += 1) {
        if (stock[i] < ingrNeeded[i])
            return false;
    }
    return true;
}

std::vector<int> MargaritaModule::getIngrNeeded()
{
    return {1, 1, 1, 0, 0, 0, 0, 0, 0};
}