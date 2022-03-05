/*
** EPITECH PROJECT, 2021
** SFML
** File description:
** Arcade
*/

#include "../../include/sfml/sfmlGraphic.hpp"

extern "C" Arcade::IGraphic *createLibrary()
{
    return new Arcade::sfmlGraphic();
}

extern "C" void destroyLibrary(Arcade::IGraphic *object)
{
	delete object;
}

std::string Arcade::sfmlGraphic::getNameLib()
{
    std::string name = "sfml";
    return name;
}

Arcade::sfmlGraphic::sfmlGraphic() = default;

Arcade::sfmlGraphic::~sfmlGraphic() = default;

Arcade::Input Arcade::sfmlGraphic::getInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		return Arcade::Input::Q_KEY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return Arcade::Input::UP_ARROW;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return Arcade::Input::LEFT_ARROW;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return Arcade::Input::DOWN_ARROW;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return Arcade::Input::RIGHT_ARROW;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		return Arcade::Input::ENTER;
	return (Arcade::Input::NO_INPUT);
}

sf::RectangleShape Arcade::sfmlGraphic::createRect()
{
	sf::Vector2f size = {40, 40};
	sf::RectangleShape rect;
	rect.setSize(size);
	rect.setFillColor(sf::Color::Blue);
	return rect;
}

sf::CircleShape Arcade::sfmlGraphic::createCircle(sf::Color color, int r)
{
	sf::CircleShape circle;
	circle.setRadius(r);
	circle.setFillColor(color);
	return circle;
}

void Arcade::sfmlGraphic::drawMap(float i, float j, sf::RectangleShape rect)
{
	sf::Vector2f pos = {i * 40, j * 40};
	rect.setPosition(pos);
	_window->draw(rect);
}

void Arcade::sfmlGraphic::drawMap(float i, float j, sf::CircleShape circle)
{
	sf::Vector2f pos = {i * 40, j * 40};
	circle.setPosition(pos);
	_window->draw(circle);
}

void Arcade::sfmlGraphic::initMap()
{
	_window->clear();
	Close();
	for (float i = 0; i < 21; i++) {
		float j = 0;
		for (; j < 21; j++) {
			if (_map[(int) j][(int) i] == '#')
				drawMap(15 + i, 2 + j, rect);
			if (_map[(int) j][(int) i] == 'P')
				drawMap(15 + i, 2 + j, pacman);
			if (_map[(int) j][(int) i] == '.')
				drawMap(15 + 0.4 + i, 2 + 0.3 + j, point);
			if (_map[(int) j][(int) i] == 'G')
				drawMap(15 + i, 2 + j, ghost);
			if (_map[(int) j][(int) i] == '$')
				drawMap(15 + 0.3 + i, 2 + 0.2 + j, bonus);
		}
	}
}

void Arcade::sfmlGraphic::playMusic()
{
	_mus = createMusic("Arcade/Graphics/image/pacman.ogg");
}

void Arcade::sfmlGraphic::closeMusic()
{
	_mus->stop();
	_mus->~Sound();
//	_music.~SoundBuffer();
}

void Arcade::sfmlGraphic::initGame(char **map)
{
	_map = map;
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade - SFML PACMAN");
	_window->setMouseCursorVisible(false);
	rect = createRect();
	pacman = createCircle(sf::Color::Yellow, 20);
	point = createCircle(sf::Color::Yellow, 5);
	ghost = createCircle(sf::Color::Red, 20);
	bonus = createCircle(sf::Color::Yellow, 10);
}

void Arcade::sfmlGraphic::display()
{
	_window->display();
}

int Arcade::sfmlGraphic::isGame()
{
	if (_window->isOpen()) return 1;
	return 0;
}

void Arcade::sfmlGraphic::close()
{
	_window->close();
}

sf::Color Arcade::sfmlGraphic::giveColor(std::string name)
{
	if (_state == 3 && name == "QUIT")
		return sf::Color::Red;
	if (name == "QUIT" && _state != 3)
		return sf::Color::Black;
	if (_state == 0) {
		std::vector<std::string> str /*= {"pacman", "nibbler"}*/;
		for (int i = 0; i < _Games.size(); i++)
			str.push_back(GameName(_Games[i]));
		if (name == str[_tab_game])
			return sf::Color::Green;
	}
	if (_state == 1) {
		std::vector<std::string> str = {"SFML", _name.c_str()};
		if (name == str[_tab_game])
			return sf::Color::Green;
	}
	return sf::Color::Yellow;
}

void Arcade::sfmlGraphic::Menu()
{
	sf::Texture texture;
	texture.loadFromFile("Arcade/Graphics/image/ArcadeMenu.png");
	sf::Sprite sprite;
	Arcade::Text sfml = {1335, 650, "SFML"};
	Arcade::Text ncurses = {1300, 780, _name.c_str()};
	Arcade::Text quit = {900, 835, "QUIT\n (Q)"};
	sprite.setTexture(texture);
	sprite.setScale(0.6, 0.6);
	sprite.setPosition(330, 60);
	_window->draw(sprite);
	for (int i = 0; i < _Games.size(); i++) {
		unsigned int y = 650 + (130 * i);
		Arcade::Text packman = {420, y, GameName(_Games[i])};
		setText(packman, giveColor(packman.text));
	}
	setText(sfml, giveColor(sfml.text));
	setText(ncurses, giveColor(ncurses.text));
	setText(quit, giveColor("QUIT"));
}

int Arcade::sfmlGraphic::Time(clock_t current_time)
{
	float interval = ((float)(clock()-current_time)/CLOCKS_PER_SEC);
	if (interval > 0.1f) return 1;
	return 0;
}

void Arcade::sfmlGraphic::showScore(unsigned int score)
{
	sf::Font font;
	font.loadFromFile("Arcade/Graphics/image/ARCADE.TTF");
	std::string s = std::to_string(score);
	sf::Text t(s, _font);
	t.setPosition(10, 10);
	t.setCharacterSize(60);
	t.setFillColor(sf::Color::Yellow);
	_window->draw(t);
}

int Arcade::sfmlGraphic::Close()
{
	int ret = 0;
	sf::Event event;
	while (_window->pollEvent(event))
		if (event.type == sf::Event::Closed) {
			_window->close();
			ret = 1;
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && _state == 3)
		_window->close();
	return ret;
}

void Arcade::sfmlGraphic::setText(Arcade::Text text, sf::Color color)
{
	sf::Text t(text.text, _font);
	t.setPosition(text.x, text.y);
	t.setCharacterSize(60);
	t.setFillColor(color);
	_window->draw(t);
}

void Arcade::sfmlGraphic::Button()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			_tab_game = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_tab_game = 0;
		if (_state == 3) _state == 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		_state = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		_state = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		_state = 0;
}

std::string Arcade::sfmlGraphic::ret_value()
{
	if (_tab_game == 0 && _state == 1)
		return "sfml";
	else if (_tab_game == 1 && _state == 1)
		return _name.c_str();
	else if (_tab_game == 0 && _state == 0)
		return GameName("Game_" + _Games[0]);
	else if (_tab_game == 1 && _state == 0)
		return GameName("Game" + _Games[1]);
	return "NULL";
}

sf::Sound *Arcade::sfmlGraphic::createMusic(std::string name)
{
	if (!_music.loadFromFile(name)) std::cerr << "Music ERROR\n";
	auto sound = new sf::Sound(_music);
	sound->setLoop(true);
	sound->play();
	return sound;
}

void Arcade::sfmlGraphic::findName(std::vector<std::string> files)
{
	for (int i = 0; i < files.size(); i++) {
		_name = files[i].substr(files[i].find_last_of('_') + 1);
		_name = _name.substr(0, _name.find_last_of('.'));
		if (_name != "sfml") break;
	}
}

std::string Arcade::sfmlGraphic::GameName(std::string files)
{
	std::string name  = files.substr(files.find_last_of('_') + 1);
	name = name.substr(0, name.find_last_of('.'));
	return name;
}

std::string Arcade::sfmlGraphic::createWindow(std::vector<std::string> files, std::vector<std::string> filesGame)
{
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade - SFML graphics");
	_window->setMouseCursorVisible(false);
	_font.loadFromFile("Arcade/Graphics/image/ARCADE.TTF");
	_tab_game = 0;
	_state = 0;
	_Games = filesGame;
	auto sound = createMusic("Arcade/Graphics/image/Menu.ogg");
	findName(files);
	while (_window->isOpen()) {
		_window->clear();
		Close();
		Button();
		Menu();
		_window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			_window->close();
	}
	sound->stop();
	sound->~Sound();
	_music.~SoundBuffer();
	std::string ret = ret_value();
	return ret;
}
