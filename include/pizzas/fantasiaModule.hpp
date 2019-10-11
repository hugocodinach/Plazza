/*
** EPITECH PROJECT, 2018
** fantasiaModule.hpp
** File description:
** include/pizzas/fantasiaModule.hpp
*/

#ifndef FANTASIA_MODULE_HPP
#define FANTASIA_MODULE_HPP

#include "IpizzaModule.hpp"

class FantasiaModule : public IPizzaModule
{

    public:
        FantasiaModule(PizzaSize_e size);
        ~FantasiaModule() final;

        PizzaType_e getPizzaType() final;
        PizzaSize_e getPizzaSize() final;
        int getCookingTime() final;
        std::string pack() final;
        bool isThereEnoughIngr(std::vector<int> stock) final;
        std::vector<int> getIngrNeeded() final;

    private:
        PizzaSize_e _size;
};

#endif