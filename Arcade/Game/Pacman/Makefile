##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile_Arcade
##

NAME	=	../../../lib/arcade_pacman.so

CC	=	g++

CPPFLAGS	=	-I./include/
CPPFLAGS	+=	-fPIC -g3

SRC		=	Pacman.cpp     \
			Ghost.cpp     \

OBJ	=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -fPIC -shared -o $(NAME) $(OBJ)

clean :
	find -name "*~" -delete , -name "*.o" -delete , -name "#*#" -delete

fclean : clean
	rm -f $(NAME)

re : fclean all