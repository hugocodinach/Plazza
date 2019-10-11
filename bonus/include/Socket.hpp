/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
    #define SOCKET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include "Command.hpp"

class Socket {
	public:
		Socket(const size_t &port, const std::string &ip = "");
		Socket(void);
		virtual ~Socket();

        virtual std::string read(void) const;
        virtual void operator>>(Command &storage);
        virtual void operator>>(std::string &storage);

        virtual void write(const std::string &data) const;
        virtual void operator<<(const Command &data) const;
        virtual void operator<<(const std::string &data) const;

        virtual void setFd(const size_t &fd) noexcept;
        virtual const int &getFd(void) const noexcept;
	protected:
        int _fd = -1;
        struct sockaddr_in _addr;
        struct sockaddr *_cast;
        socklen_t _addrlen;

	private:
};

#endif /* !SOCKET_HPP_ */
