/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Arcade
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>

namespace Arcade {

typedef struct {
		unsigned int x;
		unsigned int y;
		std::string text;
	} Text;

	typedef enum {
		NO_INPUT = -1,
		ENTER,
		BACKSPACE,
		SPACE,
		ESCAPE,
		UP_ARROW,
		DOWN_ARROW,
		LEFT_ARROW,
		RIGHT_ARROW,
		QUIT_EVENT,
		Q_KEY
    } Input;

} // end namespace Arcade

#endif