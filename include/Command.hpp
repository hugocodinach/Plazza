/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Command
*/

#ifndef COMMAND_HPP_
    #define COMMAND_HPP_

#include <string>
#include <vector>

class Command {
	public:
		Command(const size_t &fd = 1, const std::string &command = "", const std::string &data = "");
		~Command();

        const size_t &getSender(void) const noexcept;
        const std::string &getCommand(void) const noexcept;
        const std::string &getData(void) const noexcept;

        size_t _fd;
        std::string _command;
        std::string _data;
	protected:
	private:
};

#endif /* !COMMAND_HPP_ */
