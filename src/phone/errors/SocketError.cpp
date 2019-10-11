/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** SocketError
*/

#include "SocketError.hpp"

SocketError::SocketError(const std::string &message)
: _message(message)
{
    _message = "Socket : " + _message;
}

const char *SocketError::what() const noexcept
{
    return _message.data();
}