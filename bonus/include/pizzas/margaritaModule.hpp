/*
** EPITECH PROJECT, 2018
** margaritaModule.hpp
** File description:
** include/pizzas/margaritaModule.hpp
*/

#ifndef MARGARITA_MODULE_HPP
#define MARGARITA_MODULE_HPP

#include "IpizzaModule.hpp"

class MargaritaModule : public IPizzaModule
{

    public:
        MargaritaModule(PizzaSize_e size);
        ~MargaritaModule() final;

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