/*
** EPITECH PROJECT, 2021
** IGAME
** File description:
** IGAME
*/

#ifndef __IGAME_HPP__
#define __IGAME_HPP__

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>     
#include <algorithm>    
#include <vector>

#include <istream>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "../Core/include/Core.hpp"

namespace Arcade
{
    class IGame
    {
        private:
            /* data */
        public:
    		virtual void                        inputEvent(Arcade::Input input) = 0;
            virtual char                        **setArray2d() = 0;
    		virtual void                        reset() = 0;
    		virtual char                        **getGame(Arcade::Input in)=0;
        
        
            virtual                             ~IGame() = default;
            virtual void                        printMap() = 0;
            virtual void                        init() = 0;
            virtual unsigned int                getScore() = 0;
            virtual unsigned int                getPV() = 0;
            virtual char **                     update() = 0;
        
    };
}


#endif