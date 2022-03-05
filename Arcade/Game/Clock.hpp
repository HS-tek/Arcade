/*
** EPITECH PROJECT, 2021
** CLOCK
** File description:
** CLOCK
*/

#ifndef __CLOCK_HPP__
#define __CLOCK_HPP__
#include <stdio.h>      
#include <time.h>      
#include <math.h> 

class Clock
{
    private:
    clock_t _clock;
        
    public:
        Clock(/* args */);
        ~Clock();
        void restart();
        float getElapsedTime()const;
};

#endif