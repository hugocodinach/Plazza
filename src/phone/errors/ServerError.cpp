/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** ServerError
*/

#include "ServerError.hpp"

ServerError::ServerError(const std::string &message)
: SocketError(message)
{
    _message = "Server : " + message;
}
