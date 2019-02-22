##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

SRC=		src/components/4001.cpp			\
			src/components/4011.cpp			\
			src/components/4071.cpp			\
			src/components/4081.cpp			\
			src/components/AComponent.cpp	\
			src/components/Input.cpp		\
			src/components/Output.cpp		\
			src/components/Pin.cpp			\
			src/core/Commands.cpp			\
			src/core/Error.cpp				\
			src/core/Main.cpp				\
			src/parser/Factory.cpp			\
			src/parser/Parser.cpp			\

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
