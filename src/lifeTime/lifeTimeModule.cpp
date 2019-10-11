/*
** EPITECH PROJECT, 2018
** lifeTimeModule.cpp
** File description:
** src/lifeTimeModule.cpp
*/

#include "lifeTimeModule.hpp"

LifeTimeModule::LifeTimeModule(int lifeTime)
{
    _lifeTime = lifeTime;
    _start = std::chrono::steady_clock::now();
    _end = std::chrono::steady_clock::now();
}

LifeTimeModule::~LifeTimeModule()
{
}

void LifeTimeModule::reset()
{
    _start = std::chrono::steady_clock::now();
    _end = std::chrono::steady_clock::now();
}

float LifeTimeModule::getElapsedTime()
{
    std::chrono::duration<float> duration;

    _end = std::chrono::steady_clock::now();
    duration = _end - _start;
    return duration.count();
}