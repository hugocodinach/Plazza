/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** ServerError
*/

#ifndef SERVERERROR_HPP_
    #define SERVERERROR_HPP_

#include "SocketError.hpp"

class ServerError : public SocketError {
	public:
		ServerError(const std::string &message);
		virtual ~ServerError() = default;

	protected:
	private:
};

#endif /* !SERVERERROR_HPP_ */
