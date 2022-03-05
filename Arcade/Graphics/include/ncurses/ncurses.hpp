/*
** EPITECH PROJECT, 2021
** Ncurse
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_
#include <ncurses.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../IGraphic.hpp"

namespace Arcade {

class ncursesGraphic : public Arcade::IGraphic
{
private:
    void                        findName(std::vector<std::string> files);
    std::string                 color(std::string ret, WINDOW *win);
    std::string                 Button(WINDOW *win);
    std::string                 GameName(std::string files);
    
    std::string                 _name;
    int                         _state;
    int                         _tab_game;
    std::vector<std::string>    _Games;
    WINDOW *                    win;
    char **                     _map;
public:
                                ncursesGraphic();
                                ~ncursesGraphic();
    std::string                 createWindow(std::vector<std::string> files, std::vector<std::string> filesGame);
    Arcade::Input               getInput();
    std::string                 getNameLib()override;
    void                        initMap();
    void                        initGame(char **map);
    void                        display();
    int                         isGame();
    void                        close();
    void                        playMusic();
    void                        closeMusic();
    int                         Close();
    int                         Time(clock_t current_time);
    void                        showScore(unsigned int score);
};

}

extern "C" Arcade::IGraphic *createLibrary();
extern "C" void destroyLibrary(Arcade::IGraphic *library);

#endif /* NCURSES_HPP */
