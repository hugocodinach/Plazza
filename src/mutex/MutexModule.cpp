/*
** EPITECH PROJECT, 2018
** MutexModule.cpp
** File description:
** src/mutex/MutexModule.cpp
*/

#include "MutexModule.hpp"

MutexModule::MutexModule()
{

}

MutexModule::~MutexModule()
{
    
}

void MutexModule::lock()
{
    _mtx.lock();
}

void MutexModule::unlock()
{
    _mtx.unlock();
}