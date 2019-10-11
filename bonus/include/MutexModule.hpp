/*
** EPITECH PROJECT, 2018
** MutexModule.hpp
** File description:
** include/MutexModule.hpp
*/

#ifndef MUTEX_MODULE_HPP
#define MUTEX_MODULE_HPP

#include <iostream>
#include <thread>
#include <mutex>

class MutexModule
{
    public:
        MutexModule();
        ~MutexModule();

        void lock();
        void unlock();
        std::mutex &getMtx(void);
    
    private:
        std::mutex _mtx;
};

#endif