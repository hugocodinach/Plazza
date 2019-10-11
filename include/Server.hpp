/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

#include "Socket.hpp"
#include "Client.hpp"

class Server : public Socket {
	public:
		Server(const size_t &port);
		virtual ~Server();

        void init(const size_t &nbMaxClients);
        Command run(void);

        virtual void operator>>(Command &storage);
        virtual void operator>>(std::string &storage);

        virtual void operator<<(const Command &data) const;
        virtual void operator<<(const std::string &data) const;

	protected:
        void bind(void);
        void listen(const size_t &nbMaxClients) const;
        void disconnect(const size_t &clientIndex);
        Command accept(void);
        void waitActivity(void);
        Command getActivity(void);

	protected:
        fd_set _activeClients;
        fd_set _readableClients;

        Client *_clients[FD_SETSIZE];
};

/*
    ACTIVITIES :

FD CONNECTION\n
FD DISCONNECTION\n
FD MESSAGE "MESSAGE"\n
FD PIZZADONE [PIZZA]
*/

#endif /* !SERVER_HPP_ */
