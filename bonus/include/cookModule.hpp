/*
** EPITECH PROJECT, 2018
** cookModule.hpp
** File description:
** include/cookModule.hpp
*/

#ifndef COOK_MODULE_HPP
    #define COOK_MODULE_HPP

    #include <condition_variable>
    #include <thread>
    #include <chrono>
    #include "stockModule.hpp"
    #include "IpizzaModule.hpp"
    #include "pizzaQueue.hpp"
    #include "Socket.hpp"

    class CookModule {

        public:
            CookModule(StockModule *stock, int fd, PizzaQueue *queue, PizzaQueue *pizzaDoneQueue, float multiplier, int id);
            ~CookModule();

            void washHandsThenPutOnGlovesToStartWork(void);
            void waitForOrder(void);
            void waitForIngr(IPizzaModule *pizza);
            void doPizza(IPizzaModule *pizza);
            std::string getStatus(void);

        private:
            std::string _name;
            int _fd;
            StockModule *_stock;
            PizzaQueue *_queue;
            PizzaQueue *_doneQueue;
            std::string _status;
            float _multiplier;
            int _id;
    };

#endif