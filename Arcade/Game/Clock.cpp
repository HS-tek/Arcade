/*
** EPITECH PROJECT, 2021
** GAME
** File description:
** clock
*/

#include "Clock.hpp"

Clock::Clock()
{
    this->_clock = clock();
}

Clock::~Clock()
{
}

void Clock::restart()
{
    this->_clock = clock();
}

float Clock::getElapsedTime()const
{
    return ((float)(clock() - this->_clock)/ CLOCKS_PER_SEC);
}
