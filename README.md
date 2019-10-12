# Plazza

Simulation of a pizzeria, which is composed of the reception that accepts new commands, of ceveral kitchens, themselves with several cooks, themselves cooking several pizzzas. Dealing with multi-threading and sockets.

The project is divided in three parts :

### The reception:

The reception is able to receive a command, and to dispatch it in the less busy kitchen. When all the kitchens are saturated, it creates a new one.

### Kitchens:

Kitchens are able to receive orders from the reception, and to stack them. Kitchens contain cooks.

### Cooks:

Cooks are able to treat orders stacked in their kitchen. They use ingredients, refiled automatically over time.

## Technology

### [C++](https://fr.wikipedia.org/wiki/C%2B%2B)
![](https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg)

## Installation

1. **Clone** the repository
```bash
git clone https://github.com/hugocodinach/Plazza.git
```

2.  **Build**
```bash
make
```

## Start the reception

```bash
./plazza [FLOAT] [INT] [INT]
```

The first parameter is a multiplier for the cooking time of the pizzas. It can be between 0 and 1 to obtain a
divisor of the pizzas cooking time.

The second parameter is the number of cooks per kitchen.

The third parameter is the time in milliseconds, used by the kitchen stock to replace ingredients.

## Order a pizza

```bash
[pizza] [size] x[INT]
```
The first parameter is the pizza type. Here is the list :

> regina : Contains doe, tomato, gruyere, ham, mushrooms. Baked in 2 secs * multiplier.

> margarita : Contains doe, tomato and gruyere. Baked in 1 sec * multiplier.

> americana : Contains doe, tomato, gruyere, steak. Baked in 2 secs * multiplier.

> fantasia : Contains doe, tomato, eggplant, goat cheese and chief love. Baked in 4 secs * multiplier.

The second parameter is the size of the pizza.

> S

> M

> L

> XL

> XXL

The third parameter is number of pizza ordered.

> x1

> x2

> x3

> etc...
