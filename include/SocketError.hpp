/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** SocketError
*/

#ifndef SOCKETERROR_HPP_
    #define SOCKETERROR_HPP_

#include <string>
#include <exception>

class SocketError : public std::exception {
	public:
		SocketError(const std::string &message);
		virtual ~SocketError() = default;

        virtual const char *what() const noexcept override;
	protected:
        std::string _message;
	private:
};

#endif /* !SOCKETERROR_HPP_ */
