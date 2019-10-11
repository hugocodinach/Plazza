/*
** EPITECH PROJECT, 2018
** receptionModule.hpp
** File description:
** include/receptionModule.hpp
*/

#ifndef RECEPTION_MODULE_HPP
#define RECEPTION_MODULE_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <netinet/in.h>
#include <bits/stdc++.h>

#include "Server.hpp"
#include "kitchenModule.hpp"
#include "clientModule.hpp"
#include "IpizzaModule.hpp"
#include "KitchenInfo.hpp"

#define GRAPHICAL 1

class ReceptionModule : public Server {

    public:
        ReceptionModule(int ac, char **av);
        ~ReceptionModule();

        void interactiveShell(void);
        void openPizzeria(void);
        bool checkOrder(std::string order);
        void hireReceptionist(void);
        std::vector< std::pair <PizzaType_e, PizzaSize_e> > organizeClientOrder(std::string order);
        void processOrder(const std::vector< std::pair <PizzaType_e, PizzaSize_e> > &order);
        void createKitchen(float multiplier, int cookNbr, long replaceTime);
        void getPizzeriaStatus(void);

    private:
        float _multiplier;
        int _cookNbr;
        long _replaceTime;
        bool _open;
        int _prevKitchenId;
        std::vector<KitchenInfo> _register;

        PizzaType_e recoverPizzaType(std::string);
        PizzaSize_e recoverPizzaSize(std::string);
        int recoverPizzasNumber(std::string);
        void listenOrder(void);
        void listenKitchen(const Command &command);

        void addKitchenToRegister(const int &kitchenPhoneNumber) noexcept;
        void removeKitchenFromRegister(const int &kitchenPhoneNumber) noexcept;
        void updateKitchenInRegister(const int &kitchen, int offset); /* offset = -1 or 1 only */

        void sendOrderToKitchen(std::vector< std::pair <PizzaType_e, PizzaSize_e> > orders);
        void sendPizzaToKitchen(std::pair <PizzaType_e, PizzaSize_e> order, int fd);
        bool eraseFullKitchen(std::pair<size_t, int> p);
        void askKitchenStatus();
        void updateLog(std::string hallo);
};

#endif