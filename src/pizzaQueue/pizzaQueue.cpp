/*
** EPITECH PROJECT, 2018
** pizzaQueue.cpp
** File description:
** src/pizzaQueue/pizzaQueue.cpp
*/

#include "pizzaQueue.hpp"

PizzaQueue::PizzaQueue()
{
}

PizzaQueue::~PizzaQueue()
{
}

void PizzaQueue::push(IPizzaModule *pizza)
{
    std::unique_lock<std::mutex> lock(_mtx);
    _queue.push(pizza);
    _cond.notify_one();
    lock.unlock();
}

IPizzaModule *PizzaQueue::pop(void)
{
    std::unique_lock<std::mutex> lock(_mtx);
    IPizzaModule *pizza = NULL;

    if (_queue.empty())
        _cond.wait(lock);
    pizza = _queue.front();
    _queue.pop();
    lock.unlock();
    return pizza;
}