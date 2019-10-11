/*
** EPITECH PROJECT, 2018
** isInt.cpp
** File description:
** src/utils/isInt.cpp
*/

#include "main.hpp"

bool isInt(std::string str)
{
    for (size_t i = 0; i != str.size(); i += 1) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' || i != 0))
            return false;
    }
    return true;
}

bool isFloat(std::string str)
{
    bool point = false;

    for (size_t i = 0; i != str.size(); i += 1) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' || i != 0)) {
            if (str[i] == '.' && !point && i != 0 && i != str.size() - 1) {
                point = true;
                continue;
            }
            return false;
        }
    }
    return true;
}