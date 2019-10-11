/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Server
*/

#include <cerrno>
#include <cstring>
#include <clocale>
#include "Server.hpp"
#include "ServerError.hpp"

Server::Server(const size_t &port)
: Socket(port)
{
    int tmp = 1;

    if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &tmp, sizeof(int)) == -1)
        throw ServerError("Instanciation error (setsockopt)");
    FD_ZERO(&_activeClients);
    FD_ZERO(&_readableClients);
    FD_SET(_fd, &_activeClients);
    for (size_t i = 0; i != FD_SETSIZE; i++)
        _clients[i] = nullptr;
}

Server::~Server()
{
    for (size_t i = 0; i != FD_SETSIZE; i++)
        delete(_clients[i]);
}

void Server::init(const size_t &nbMaxClients)
{
    bind();
    listen(nbMaxClients);
}

Command Server::run(void)
{
    waitActivity();
    return getActivity();
}

void Server::bind(void)
{
    if (::bind(_fd, _cast, _addrlen) == -1)
        throw ServerError("Binding error : " + std::string(std::strerror(errno)));
}

void Server::listen(const size_t &nbMaxClients) const
{
    if (::listen(_fd, nbMaxClients) == -1)
        throw ServerError("Listen error : " + std::string(std::strerror(errno)));
}

Command Server::accept(void)
{
    Client *client = new Client;

    client->getAccepted(_fd);
    _clients[client->getFd()] = client;
    FD_SET(client->getFd(), &_activeClients);
    return Command(client->getFd(), "CONNECTION", "");
}

void Server::disconnect(const size_t &clientIndex)
{
    if (!_clients[clientIndex])
        throw ServerError("Disconnect error : no client at index " + std::to_string(clientIndex));
    FD_CLR(_clients[clientIndex]->getFd(), &_activeClients);
    delete(_clients[clientIndex]);
    _clients[clientIndex] = nullptr;
}

void Server::waitActivity(void)
{
    _readableClients = _activeClients;
    if (select(FD_SETSIZE, &_readableClients, nullptr, nullptr, nullptr) == -1)
        throw ServerError("waitActivity -> select : " + std::string(std::strerror(errno)));
}

Command Server::getActivity(void)
{
    Command command(0, "", "");

    for (int i = 0; i != FD_SETSIZE; i++)
        if (FD_ISSET(i, &_readableClients)) {
            if (i == _fd) {
                return accept();
            } else {
                if (!_clients[i])
                    throw ServerError("getActivity Error : no client at fd " + std::to_string(i));
                *_clients[i] >> command;
                return command;
            }
        }
    throw ServerError("getActivity : Unknowed activity ???");
    return command;
}

void Server::operator>>(Command &storage)
{
    Socket::operator>>(storage);
}

void Server::operator>>(std::string &storage)
{
    Socket::operator>>(storage);
}

void Server::operator<<(const Command &data) const
{
    Socket::operator<<(data);
}

void Server::operator<<(const std::string &data) const
{
    Socket::operator<<(data);
}
