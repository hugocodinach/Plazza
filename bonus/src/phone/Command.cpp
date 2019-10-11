/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Command
*/

#include "Command.hpp"

Command::Command(const size_t &fd, const std::string &command, const std::string &data)
: _fd(fd),
_command(command),
_data(data)
{
}

Command::~Command()
{
}

const size_t &Command::getSender(void) const noexcept
{
    return _fd;
}

const std::string &Command::getCommand(void) const noexcept
{
    return _command;
}

const std::string &Command::getData(void) const noexcept
{
    return _data;
}
