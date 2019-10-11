/*
** EPITECH PROJECT, 2018
** reginaModule.hpp
** File description:
** include/pizzas/reginaModule.hpp
*/

#ifndef REGINA_MODULE_HPP
#define REGINA_MODULE_HPP

#include "IpizzaModule.hpp"

class ReginaModule : public IPizzaModule
{

    public:
        ReginaModule(PizzaSize_e size);
        ~ReginaModule() final;

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