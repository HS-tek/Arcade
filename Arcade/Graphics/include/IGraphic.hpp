/*
** EPITECH PROJECT, 2021
** IGRAPHIC
** File description:
** IGRAPHIC
*/

#ifndef __IGRAPHIC_HPP__
#define __IGRAPHIC_HPP__

//add Vec2.hpp & Event.hpp

#include <iostream>
#include <vector>
#include "../../Core/include/Core.hpp"

namespace Arcade
{
    class IGraphic
    {
        private:
            /* data */
        public:
            virtual                     ~IGraphic() = default;
            virtual std::string         createWindow(std::vector<std::string> files, std::vector<std::string> filesGame) = 0;
            virtual Arcade::Input       getInput() = 0;
            virtual std::string         GameName(std::string files) = 0;
            virtual std::string         getNameLib() = 0;
            virtual void                initMap() = 0;
            virtual void                initGame(char **map) = 0;
            virtual void                display() = 0;
            virtual int                 isGame() = 0;
            virtual void                close() = 0;
            virtual void                playMusic() = 0;
            virtual void                closeMusic() = 0;
            virtual int                 Close() = 0;
            virtual int                 Time(clock_t current_time) = 0;
            virtual void                showScore(unsigned int score) = 0;
    };
}


#endif
