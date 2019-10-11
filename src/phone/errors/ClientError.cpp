/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** ClientError
*/

#include "ClientError.hpp"

ClientError::ClientError(const std::string &message)
: SocketError(message)
{
    _message = "Client : " + message;
}
