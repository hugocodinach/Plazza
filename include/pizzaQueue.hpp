/*
** EPITECH PROJECT, 2018
** pizzaQueue.hpp
** File description:
** include/pizzaQueue.hpp
*/

#ifndef PIZZA_QUEUE_HPP
#define PIZZA_QUEUE_HPP

#include <queue>
#include <chrono>
#include <thread>
#include <condition_variable>
#include "IpizzaModule.hpp"
#include "MutexModule.hpp"

class PizzaQueue {

    public:
        PizzaQueue();
        ~PizzaQueue();

        void push(IPizzaModule *pizza);
        IPizzaModule * pop(void);
        void displayStatus(void);

    private:
        std::queue<IPizzaModule *> _queue;
        std::mutex _mtx;
        std::condition_variable _cond;
};

#endif