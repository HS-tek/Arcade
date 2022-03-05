/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Arcade
*/

#include "../include/Arcade.hpp"
#include "../../Graphics/include/IGraphic.hpp"
#include "../../Game/IGame.hpp"

ArcadeApp::ArcadeApp(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "./arcade lib" << std::endl;
        exit(84);
    }
    auto file = std::string(av[1]);
    _loadLib.load(file);
    _files = find_file();
    _filesGame = findGames();
    auto createLibFunc = _loadLib.getLibFunc("createLibrary");
    auto raw = ((Arcade::IGraphic *(*)()) createLibFunc)();
    std::string g = raw->createWindow(_files, _filesGame);
    _graphic = raw->GameName(file);
    std::vector<std::string> game = {"pacman", "nibbler"};
    while (g != game[0] && g != game[1] && g != "NULL")
        g = CoreLoop(g);
    //std::cout << "We are playing " << g << std::endl;
    if (g == "NULL") exit(0);
    PlayGame(g);
}

ArcadeApp::~ArcadeApp()
{
}

const std::vector<std::string> ArcadeApp::find_file()
{
    std::vector<std::string> files;
	DIR *dirp = opendir("lib/");
	struct dirent *dp = readdir(dirp);
    loadLib lib;

	while (dp != nullptr) {
		auto fileName = std::string(dp->d_name);
		if (fileName != ".." && fileName != "."
			&& fileName.substr(fileName.find_last_of('.') + 1)
			== "so") {
            lib.load("lib/" + fileName);
            if (lib.LibType("Library"))
			    files.push_back(fileName);
            }
		dp = readdir(dirp);
	}
	closedir(dirp);
	return files;
}

const std::vector<std::string> ArcadeApp::findGames()
{
    std::vector<std::string> files;
	DIR *dirp = opendir("lib/");
	struct dirent *dp = readdir(dirp);
    loadLib lib;

	while (dp != nullptr) {
		auto fileName = std::string(dp->d_name);
		if (fileName != ".." && fileName != "."
			&& fileName.substr(fileName.find_last_of('.') + 1)
			== "so") {
            lib.load("lib/" + fileName);
            if (lib.LibType("Game"))
			    files.push_back(fileName);
            }
		dp = readdir(dirp);
	}
	closedir(dirp);
	return files;
}

std::string ArcadeApp::CoreLoop(std::string file)
{
    _loadLib.load("lib/arcade_"+file+".so");
    auto createLibFunc = _loadLib.getLibFunc("createLibrary");
    auto raw = ((Arcade::IGraphic *(*)()) createLibFunc)();
    std::string g = raw->createWindow(_files, _filesGame);
    _graphic = raw->getNameLib();
    if (g == "sfml" || g == "ncurses") {
        return g;
    }
    for (int i = 0; i < 1; i++)
        if (g == _filesGame[i])
            return g.substr(g.find_last_of('_') + 1);
    return g;
}

void ArcadeApp::PlayGame(std::string Game)
{
    loadLib libGame;
    clock_t current_time = clock();
    libGame.load("lib/arcade_" + Game + ".so");
    auto createGameFunc = libGame.getLibFunc("createGame");
    auto rawGame = ((Arcade::IGame *(*)()) createGameFunc)();
    auto createGraphFunc = _loadLib.getLibFunc("createLibrary");
    auto rawGraph = ((Arcade::IGraphic *(*)()) createGraphFunc)();
    Arcade::Input in = Arcade::Input::NO_INPUT;
    char **map = rawGame->getGame(in);
    rawGraph->initGame(map);
    rawGraph->playMusic();
    while (1) {
        in = Arcade::Input::NO_INPUT;
        in = rawGraph->getInput();
        if (in == Arcade::Input::Q_KEY || rawGraph->Close()) {
            rawGraph->close();
            break;
        }
        map = rawGame->update();
        if (rawGraph->Time(current_time) ) {
            current_time = clock();
            if (!rawGraph->isGame()) break;
            map = rawGame->getGame(in);
        }
        rawGraph->initMap();
        rawGraph->showScore(rawGame->getScore());
        rawGraph->display();
    }
    rawGraph->closeMusic();
    rawGraph->~IGraphic();
}