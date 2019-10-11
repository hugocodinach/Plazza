/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** src/main.cpp
*/

#include "main.hpp"
#include "receptionModule.hpp"
#include "kitchenModule.hpp"

int main(int ac, char **av)
{
    ReceptionModule reception(ac, av);

    reception.hireReceptionist();
    reception.openPizzeria();
    reception.interactiveShell();
    return 0;
}