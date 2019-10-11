/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** ClientError
*/

#ifndef CLIENTERROR_HPP_
    #define CLIENTERROR_HPP_

#include "SocketError.hpp"

class ClientError : public SocketError {
	public:
		ClientError(const std::string &message);
		virtual ~ClientError() = default;

	protected:
	private:
};

#endif /* !CLIENTERROR_HPP_ */
