##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile_Arcade
##

NAME	=	../../../../lib/arcade_ncurses.so

CC	=	g++

CPPFLAGS	=	-I./include/
CPPFLAGS	+=	-fPIC

SRC		=	ncurses.cpp      \

OBJ	=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -shared -o $(NAME) -lncurses

clean :
	find -name "*~" -delete , -name "*.o" -delete , -name "#*#" -delete

fclean : clean
	rm -f $(NAME)

re : fclean all