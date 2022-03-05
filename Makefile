##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile_Arcade
##

all:
	@make --no-print-directory -C Arcade/Graphics/src/ncurses
	@make --no-print-directory -C Arcade/Graphics/src/sfml
	@make --no-print-directory -C Arcade/Core
	@make --no-print-directory -C Arcade/Game/Pacman
	@make --no-print-directory -C Arcade/Game/Nibbler

core:
	@make --no-print-directory -C Arcade/Core

graphicals:
	@make --no-print-directory -C Arcade/Graphics/src/ncurses
	@make --no-print-directory -C Arcade/Graphics/src/sfml

games:
	@make --no-print-directory -C Arcade/Game/Pacman
	@make --no-print-directory -C Arcade/Game/Nibbler

clean:
	@make clean --no-print-directory -C Arcade/Graphics/src/ncurses
	@make clean --no-print-directory -C Arcade/Graphics/src/sfml
	@make clean --no-print-directory -C Arcade/Core
	@make clean --no-print-directory -C Arcade/Game/Pacman
	@make clean --no-print-directory -C Arcade/Game/Nibbler

fclean:
	@make fclean --no-print-directory -C Arcade/Graphics/src/ncurses
	@make fclean --no-print-directory -C Arcade/Graphics/src/sfml
	@make fclean --no-print-directory -C Arcade/Core
	@make fclean --no-print-directory -C Arcade/Game/Pacman
	@make fclean --no-print-directory -C Arcade/Game/Nibbler

re:
	@make re --no-print-directory -C Arcade/Graphics/src/ncurses
	@make re --no-print-directory -C Arcade/Graphics/src/sfml
	@make re --no-print-directory -C Arcade/Core
	@make re --no-print-directory -C Arcade/Game/Pacman
	@make re --no-print-directory -C Arcade/Game/Nibbler