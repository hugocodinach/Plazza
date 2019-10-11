/*
** EPITECH PROJECT, 2018
** exitPizzeria.cpp
** File description:
** src/utils/exitPizzeria.cpp
*/

#include "main.hpp"

void exitPizzeria(void)
{
    dprintf(2, "Bad usage:\n\t./plazza [INT] [FLOAT] [INT]\n");
    exit(84);
}

void exitNegativeArg(void)
{
    dprintf(2, "Bad usage:\tArguments must be positives values.\n");
    exit(84);
}