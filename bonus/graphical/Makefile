##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	g++

LDFLAGS	=	-L. -lpthread -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS	=	-std=c++11 -I include/ -I include/pizzas/ -Wall -Werror -Wextra -g3

SRC	=	src/main.cpp		\
		src/Interface.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	graphical

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all