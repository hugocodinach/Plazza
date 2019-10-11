/*
** EPITECH PROJECT, 2018
** IpizzaModule.hpp
** File description:
** include/pizzaModule.hpp
*/

#ifndef IPIZZA_MODULE_HPP
#define IPIZZA_MODULE_HPP

#include <iostream>
#include <vector>

typedef enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
    END_SIZE = -1,
} PizzaSize_e;

typedef enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
    END_TYPE = -1,
} PizzaType_e;

const std::vector< std::pair<std::string, PizzaSize_e> > pizzaSizeList = {
    {"S", S},
    {"M", M},
    {"L", L},
    {"XL", XL},
    {"XXL", XXL},
};

const std::vector< std::pair<std::string, PizzaType_e> > pizzaTypeList = {
    {"regina", Regina},
    {"margarita", Margarita},
    {"americana", Americana},
    {"fantasia", Fantasia},
};

class IPizzaModule {

    public:
        virtual ~IPizzaModule() = default;

        virtual PizzaType_e getPizzaType() = 0;
        virtual PizzaSize_e getPizzaSize() = 0;
        virtual int getCookingTime() = 0;
        virtual bool isThereEnoughIngr(std::vector<int> stock) = 0;
        virtual std::string pack() = 0;
        virtual std::vector<int> getIngrNeeded() = 0;
};

#endif