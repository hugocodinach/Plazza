/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

#include "Socket.hpp"

class Client : public Socket {
	public:
		Client(const size_t &port, const std::string &ip);
		Client(void);
		~Client();

        static int _prevId;

        //Client &operator=(const Client &other);
        void getAccepted(const size_t &serverFd);
        void connect(void);

        virtual void operator>>(Command &storage);
        virtual void operator>>(std::string &storage);

        virtual void operator<<(const Command &data) const;
        virtual void operator<<(const std::string &data) const;
	protected:
	private:
};

#endif /* !CLIENT_HPP_ */
