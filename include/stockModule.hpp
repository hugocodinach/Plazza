/*
** EPITECH PROJECT, 2018
** stockModule.hpp
** File description:
** include/stockModule.hpp
*/

#ifndef STOCK_MODULE_HPP
#define STOCK_MODULE_HPP

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "IpizzaModule.hpp"

typedef enum ingredients {
    DOE,
    TOMATO,
    GRUYERE,
    EGGPLANT,
    HAM,
    STEAK,
    GOAT_CHEESE,
    MUSHROOMS,
    CHIEF_LOVE,
    I_END,
} ingredients_e;

class StockModule
{
    public:
        StockModule(long replenishTime);
        ~StockModule();

        std::vector<int> getStock();
        bool tryStock(IPizzaModule *pizza);
        void waitingForDeliveryTruck();
        void replenish();
        void run();

    private:
        std::vector<int> _stock;
        long _replenishTime;
        std::mutex _mtx;
};

#endif