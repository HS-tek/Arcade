/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP
#define ARCADE_HPP

#include <memory>
#include "loadLib.hpp"
#include <vector>
#include <dirent.h>
#include "Core.hpp"
#include "../../Graphics/include/IGraphic.hpp"

class ArcadeApp
{
public:
    ArcadeApp(int ac, char **av);
    ~ArcadeApp();

private:
    loadLib                                             _loadLib;
    std::shared_ptr<Arcade::IGraphic>                   _curentLib;
    std::vector<std::shared_ptr<Arcade::IGraphic>>      _libraries;
    std::vector<std::string>                            _files;
    std::vector<std::string>                            _filesGame;
    const std::vector<std::string>                      find_file();
    const std::vector<std::string>                      findGames();
    std::string                                         CoreLoop(std::string file);
    void                                                PlayGame(std::string Game);
    Arcade::Input                                       _input;
    std::string                                         _graphic;
    clock_t                                             _run;
    
};

void nullDestructorILibrary(Arcade::IGraphic *lib);

#endif
