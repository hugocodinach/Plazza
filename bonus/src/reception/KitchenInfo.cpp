/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** KitchenInfo
*/

#include "KitchenInfo.hpp"

KitchenInfo::KitchenInfo(const int &phoneNumber)
: _phoneNumber(phoneNumber)
{
}

const int &KitchenInfo::getPhoneNumber(void) const noexcept
{
    return _phoneNumber;
}

const size_t &KitchenInfo::getCurrentOrders(void) const noexcept
{
    return _currentOrders;
}

void KitchenInfo::setPhoneNumber(const int &newPhoneNumber) noexcept
{
    _phoneNumber = newPhoneNumber;
}

void KitchenInfo::setCurrentOrders(const size_t &value) noexcept
{
    _currentOrders = value;
}

bool KitchenInfo::operator==(const int &phoneNumber)
{
    return _phoneNumber == phoneNumber;
}