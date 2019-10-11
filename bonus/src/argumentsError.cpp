/*
** EPITECH PROJECT, 2018
** CCP_plazza_2018
** File description:
** src/argumentsError.cpp
*/

#include "main.hpp"
#include "macro.hpp"

int argumentsError(int ac, char **av)
{
    double multiplier = 0;
    int cookNbr = 0;
    long int replaceTime = 0;

    if (ac != 4 || !isFloat(av[1]) || !isInt(av[2]) || !isFloat(av[3]))
        exitPizzeria();
    multiplier = atof(av[1]);
    cookNbr = atoi(av[2]);
    replaceTime = atol(av[3]);
    if (multiplier < 0 || cookNbr < 0 || replaceTime < 0)
        exitNegativeArg();
    return OK;
}