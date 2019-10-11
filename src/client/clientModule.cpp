/*
** EPITECH PROJECT, 2018
** clientModule.cpp
** File description:
** src/client/clientModule.cpp
*/

#include "clientModule.hpp"

ClientModule::ClientModule()
{
    _fd = -1;
}

ClientModule::~ClientModule()
{
    if (_fd != -1)
        close(_fd);
}