##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

SRC=		src/AComponent.cpp	\
			src/Factory.cpp		\
			src/Main.cpp		\
			src/Parser.cpp		\
			src/Pin.cpp

OBJ=		$(SRC:.cpp=.o)

NAME=		nanotekspice

CFLAGS=		-Wall -Wextra -Werror

CPPFLAGS=	-I include/

all: 		$(NAME)

$(NAME): 	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(CFLAGS) $(CPPFLAGS)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re
