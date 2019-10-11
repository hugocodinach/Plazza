/*
** EPITECH PROJECT, 2018
** kitchenModule.hpp
** File description:
** include/kitchenModule.hpp
*/

#ifndef KITCHEN_MODULE_HPP
#define KITCHEN_MODULE_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include "stockModule.hpp"
#include "cookModule.hpp"
#include "pizzaQueue.hpp"
#include "Client.hpp"
#include "threadPoolModule.hpp"
#include "lifeTimeModule.hpp"

#define CODE_600 "600 status"
#define CODE_601 "601 log status"
#define CODE_700 "700"
#define CODE_900 "900 close down"

#define CODE_800 "800"
#define CODE_950 "950 kitchen closed down"


class KitchenModule : public Client {

    public:
        KitchenModule(float multiplier, int cookNbr, long replaceTime, int kitchenId);
        ~KitchenModule();

        void TurnOnTheStovesAndPreheatTheOvens();
        void createAnOrderPostItForTheCook(std::string command);

        void sendKitchenStatus(std::string command);
        void sendNewOrderToCooks(std::string command);
        void closeDownKitchen(std::string command);
        void checkPizzaDone();
        void logKitchenStatus(std::string command);

        IPizzaModule *unpack(std::string pizza);

        void handleDismissal();


    private:
        float _multiplier;
        int _cookNbr;
        int _kitchenId;

        StockModule *_ingredientStock;
        ThreadPoolModule _threadPool;
        std::vector<CookModule> _cooks;
        PizzaQueue *_pizzaQueue;
        PizzaQueue *_pizzaDoneQueue;

        LifeTimeModule _lifeTime;
};

#endif