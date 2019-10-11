/*
** EPITECH PROJECT, 2018
** word_array.c
** File description:
** src/word_array.c
*/

#include <string.h>
#include "main.hpp"

int wordNbr(std::string str)
{
    int nbr = 0;
    size_t len = str.size();

    for (size_t i = 0; i < len; i += 1) {
        for (; i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\r');
        i += 1);
        if (i < len) {
            nbr += 1;
            for (; i < len && str[i] != ' ' && str[i] != '\n' &&
            str[i] != '\r'; i += 1);
        }
    }
    return (nbr);
}

std::vector<std::string> wordArray(std::string str)
{
    size_t size = wordNbr(str);
    std::vector<std::string> array;
    size_t u = 0;
    size_t save = 0;
    size_t len = str.size();
    size_t t = 0;

    for (size_t i = 0; i < size; i += 1) {
        for (; u < len && (str[u] == ' ' || str[u] == '\n' || str[u] == '\r');
        u += 1);
        save = u;
        for (; u < len && str[u] != ' ' && str[u] != '\n' && str[u] != '\r';
        u += 1);
        array.push_back("");
        for (t = 0; save != u; save += 1, t += 1)
            array[i] += str[save];
    }
    return (array);
}