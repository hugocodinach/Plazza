/*
** EPITECH PROJECT, 2018
** threadPool.hpp
** File description:
** include/threadPool.hpp
*/

#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include "main.hpp"
#include "cookModule.hpp"

class ThreadPoolModule
{
    public:
        ThreadPoolModule();
        ~ThreadPoolModule();

        void run(std::vector<CookModule> &cooks);
        void runCook(CookModule &cook);

    private:
        std::vector<std::thread> _threads;
};

#endif