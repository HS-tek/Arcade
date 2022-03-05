#ifndef __SFML_GRAPHIC_HPP__
#define __SFML_GRAPHIC_HPP__

//add : Clock.hpp
#include "../IGraphic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

namespace Arcade {

class sfmlGraphic : public Arcade::IGraphic
{
    private:
        sf::RenderWindow *          _window;
        sf::Event                   sfEvent;
        sf::Font                    _font;
        int                         _tab_game;
        int                         _state;
        sf::SoundBuffer             _music;
        sf::Sound*                  _mus;
        std::vector<std::string>    _Games;
        sf::RectangleShape          rect;
        sf::CircleShape             pacman;
        sf::CircleShape             point;
        sf::CircleShape             ghost;
        sf::CircleShape             bonus;
        char **                     _map;
        
        void                        Menu();
        sf::Color                   giveColor(std::string name);
        void                        Button();
        std::string                 ret_value();
        
        
    public:
                                sfmlGraphic();
                                ~sfmlGraphic();
        
        std::string             createWindow(std::vector<std::string> files, std::vector<std::string> filesGame);
        Arcade::Input           getInput();
        void                    setText(Arcade::Text text, sf::Color color);
        sf::Sound *             createMusic(std::string name);
        void                    findName(std::vector<std::string> files);
        std::string             GameName(std::string files);
        std::string             getNameLib()override;
        sf::RectangleShape      createRect();
        sf::CircleShape         createCircle(sf::Color color, int r);
        void                    drawMap(float i, float j, sf::RectangleShape rect);
        void                    drawMap(float i, float j, sf::CircleShape circle);
        void                    initMap();
        void                    initGame(char **map);
        void                    display();
        int                     isGame();
        void                    close();
        int                     Close();
        void                    playMusic();
        void                    closeMusic();
        int                     Time(clock_t current_time);
        void                     showScore(unsigned int score);
        
        std::string             _name;
        Arcade::Input           _input;
};

}

extern "C" Arcade::IGraphic *createLibrary();
extern "C" void destroyLibrary(Arcade::IGraphic *library);

#endif
