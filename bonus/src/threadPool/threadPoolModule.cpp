/*
** EPITECH PROJECT, 2018
** threadPoolModule.cpp
** File description:
** src/threadPool/threadPoolModule.cpp
*/

#include "main.hpp"
#include "threadPoolModule.hpp"

ThreadPoolModule::ThreadPoolModule()
{
}

ThreadPoolModule::~ThreadPoolModule()
{
}

void ThreadPoolModule::run(std::vector<CookModule> &cooks)
{
    for (size_t i = 0; i < cooks.size(); i += 1)
        _threads.push_back(std::thread([this, &cooks, i]() { runCook(cooks[i]); }));
}

void ThreadPoolModule::runCook(CookModule &cook)
{
    cook.washHandsThenPutOnGlovesToStartWork();
}