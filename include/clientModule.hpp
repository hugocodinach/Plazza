/*
** EPITECH PROJECT, 2018
** client.hpp
** File description:
** include/client.hpp
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

class ClientModule {
    public:
        ClientModule();
        ~ClientModule();

    private:
        int _fd;
        struct sockaddr_in _client;
};

#endif