/*
** EPITECH PROJECT, 2018
** lifeTime.hpp
** File description:
** include/lifeTimeModule.hpp
*/

#ifndef LIFE_TIME_MODULE
#define LIFE_TIME_MODULE

#include <chrono>
#include "main.hpp"

class LifeTimeModule
{
    public:
        LifeTimeModule(int lifeTIme);
        ~LifeTimeModule();

        void reset();
        float getElapsedTime();

    private:
        std::chrono::time_point<std::chrono::steady_clock> _start;
        std::chrono::time_point<std::chrono::steady_clock> _end;
        int _lifeTime;
};

#endif