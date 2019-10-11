/*
** EPITECH PROJECT, 2018
** americanaModule.hpp
** File description:
** include/pizzas/americanaModule.hpp
*/

#ifndef AMERICANA_MODULE_HPP
#define AMERICANA_MODULE_HPP

#include "IpizzaModule.hpp"

class AmericanaModule : public IPizzaModule
{

    public:
        AmericanaModule(PizzaSize_e size);
        ~AmericanaModule() final;

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