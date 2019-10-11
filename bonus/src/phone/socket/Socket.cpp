/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Socket
*/

#include <cerrno>
#include <cstring>
#include <clocale>
#include <unistd.h>
#include <sstream>
#include "Socket.hpp"
#include "SocketError.hpp"

Socket::Socket(const size_t &port, const std::string &ip)
{
    if (port < 1024 || port > 65535)
        throw SocketError("Invalid port number " + std::to_string(port));
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(port);
    if (ip.empty() == true) {
        _addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    } else
        _addr.sin_addr.s_addr = inet_addr(ip.c_str());
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_fd == -1)
        throw SocketError("Instanciation error : " + std::string(std::strerror(errno)));
    _cast = (struct sockaddr *)&_addr;
    _addrlen = sizeof(struct sockaddr_in);

}

Socket::Socket(void)
{
    _fd = -1;
    _cast = (struct sockaddr *)&_addr;
    _addrlen = sizeof(struct sockaddr_in);
}

Socket::~Socket()
{
    // if (close(_fd) == -1)
    //     throw SocketError("Close error : " + std::string(std::strerror(errno)));
}


std::string Socket::read(void) const
{
    FILE *reader = fdopen(_fd, "r");
    char *buffer = nullptr;
    size_t bufSize;
    std::string result;

    if (!reader)
        throw SocketError("Read -> fdopen error : " + std::string(std::strerror(errno)));
    if (getline(&buffer, &bufSize, reader) == -1) {
        result = std::to_string(_fd) + " DISCONNECTION";
    } else {
        result = std::string(buffer);
        free(buffer);
    }
    return result;
}

void Socket::operator>>(Command &storage)
{
    std::string line = this->read();
    std::istringstream iss(line);
    std::string buffer;
    int spaces = 0;

    for (auto &iter : line)
        if (iter == ' ')
            spaces++;
    if (spaces < 1)
        throw SocketError("Bad message format (\"FD_SEND COMMAND[ DATA]\") got : " + line);
    getline(iss, buffer, ' ');
    storage._fd = atoi(buffer.c_str());
    if (spaces == 1) {
        getline(iss, buffer);
        storage._command = buffer;
    } else {
        getline(iss, buffer, ' ');
        storage._command = buffer;
        getline(iss, buffer);
        storage._data = buffer;
    }
}

void Socket::operator>>(std::string &storage)
{
    storage = this->read();
}

void Socket::write(const std::string &data) const
{
    ::write(_fd, data.c_str(), data.size());
}

void Socket::operator<<(const Command &data) const
{
    std::string command = std::to_string(data._fd) + " " + data._command + " " + data._data;
    this->write(command);
}

void Socket::operator<<(const std::string &data) const
{
    this->write(data);
}

void Socket::setFd(const size_t &fd) noexcept
{
    _fd = fd;
}

const int &Socket::getFd(void) const noexcept
{
    return _fd;
}