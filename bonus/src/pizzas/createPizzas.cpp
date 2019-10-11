/*
** EPITECH PROJECT, 2018
** createPizzas.cpp
** File description:
** src/pizzas/createPizzas.cpp
*/


#include "IpizzaModule.hpp"
#include "americanaModule.hpp"
#include "fantasiaModule.hpp"
#include "margaritaModule.hpp"
#include "reginaModule.hpp"

IPizzaModule *createAmericana(PizzaSize_e size)
{
    return new AmericanaModule(size);
}

IPizzaModule *createFantasia(PizzaSize_e size)
{
    return new FantasiaModule(size);
}

IPizzaModule *createMargarita(PizzaSize_e size)
{
    return new MargaritaModule(size);
}

IPizzaModule *createRegina(PizzaSize_e size)
{
    return new ReginaModule(size);
}