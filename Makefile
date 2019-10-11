##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	g++

LDFLAGS	=	-L. -lpthread

CXXFLAGS	=	-std=c++11 -I include/ -I include/pizzas/ -Wall -Werror -Wextra -g3

SRC	=	src/argumentsError.cpp	\
		src/exitPizzeria.cpp	\
		src/main.cpp	\
		src/mutex/MutexModule.cpp	\
		src/client/clientModule.cpp	\
		src/cook/cookModule.cpp	\
		src/kitchen/kitchenModule.cpp	\
		src/lifeTime/lifeTimeModule.cpp	\
		src/pizzaQueue/pizzaQueue.cpp	\
		src/pizzas/americanaModule.cpp	\
		src/pizzas/createPizzas.cpp	\
		src/pizzas/fantasiaModule.cpp	\
		src/pizzas/margaritaModule.cpp	\
		src/pizzas/reginaModule.cpp	\
		src/reception/receptionModule.cpp	\
		src/reception/KitchenInfo.cpp	\
		src/stock/stockModule.cpp	\
		src/utils/isInt.cpp	\
		src/utils/semilicon_array.cpp	\
		src/utils/word_array.cpp	\
		src/phone/Command.cpp	\
		src/phone/client/Client.cpp	\
		src/phone/errors/ClientError.cpp	\
		src/phone/errors/ServerError.cpp	\
		src/phone/errors/SocketError.cpp	\
		src/phone/server/Server.cpp	\
		src/phone/socket/Socket.cpp	\
		src/threadPool/threadPoolModule.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	plazza

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all