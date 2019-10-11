/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** KitchenInfo
*/

#ifndef KITCHENINFO_HPP_
    #define KITCHENINFO_HPP_

#include <cstddef>

class KitchenInfo {
	public:
		KitchenInfo(const int &phoneNumber);
		virtual ~KitchenInfo() = default;

        const int &getPhoneNumber(void) const noexcept;
        const size_t &getCurrentOrders(void) const noexcept;
        void setPhoneNumber(const int &newPhoneNumber) noexcept;
        void setCurrentOrders(const size_t &value) noexcept;


        bool operator==(const int &phoneNumber);
	protected:
        int _phoneNumber;
        size_t _currentOrders = 0;
	private:
};

#endif /* !KITCHENINFO_HPP_ */
