/*
** EPITECH PROJECT, 2018
** main.hpp
** File description:
** include/main.hpp
*/

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include "IpizzaModule.hpp"

bool isInt(std::string str);
bool isFloat(std::string str);
void exitPizzeria(void);
void exitNegativeArg(void);
int argumentsError(int ac, char **av);
std::vector<std::string> wordArray(std::string str);
IPizzaModule *createAmericana(PizzaSize_e size);
IPizzaModule *createFantasia(PizzaSize_e size);
IPizzaModule *createMargarita(PizzaSize_e size);
IPizzaModule *createRegina(PizzaSize_e size);
std::vector<std::string> semiliconArray(std::string str);

#endif