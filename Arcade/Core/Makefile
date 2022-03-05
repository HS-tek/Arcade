##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile_Arcade
##

NAME	=	../../arcade

CC	=	g++ -o

CPPFLAGS	=	-Wall -Wextra -Werror -g3
CPPFLAGS	+=	-I./include/
LDFLAGS     =   -ldl

SRC	=	src/main.cpp		\
		src/Arcade.cpp		\
		src/loadLib.cpp		\

OBJ	=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(NAME) $(OBJ) $(LDFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all