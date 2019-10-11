/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Client
*/

#include <cerrno>
#include <cstring>
#include <clocale>
#include "Client.hpp"
#include "ClientError.hpp"

Client::Client(const size_t &port, const std::string &ip)
: Socket(port, ip)
{
}

Client::Client(void)
: Socket()
{
}

Client::~Client()
{
}

// Client &Client::operator=(const Client &other)
// {
    // if (this == &other)
        // return *this;
    // this->_addr.sin_addr.s_addr = other._addr.sin_addr.s_addr;
    // this->_addr.sin_family = other._addr.sin_family;
    // this->_addr.sin_port = other._addr.sin_port;
    // for (int i = 0; i != 8; i++)
        // this->_addr.sin_zero[i] = other._addr.sin_zero[i];
    // this->_addrlen = other._addrlen;
    // this->_fd = other._fd;
    // return *this;
// }

void Client::getAccepted(const size_t &serverFd)
{
    if (_fd != -1)
        throw ClientError("getAccepted error : you are trying to accept a client side socket (and not a server side)");
    _fd = accept(serverFd, _cast, &_addrlen);
    if (_fd == -1)
        throw ClientError("getAccepted error : " + std::string(std::strerror(errno)));
}

void Client::operator>>(Command &storage)
{
    Socket::operator>>(storage);
}

void Client::operator>>(std::string &storage)
{
    Socket::operator>>(storage);
}

void Client::operator<<(const Command &data) const
{
    Socket::operator<<(data);
}

void Client::operator<<(const std::string &data) const
{
    Socket::operator<<(data);
}

void Client::connect(void)
{
    if (::connect(_fd, _cast, _addrlen) == -1)
        throw ClientError("Connect error :" + std::string(std::strerror(errno)));
}