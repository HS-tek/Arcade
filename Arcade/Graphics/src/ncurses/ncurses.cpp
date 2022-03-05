/*
** EPITECH PROJECT, 2021
** Ncurse
** File description:
** ncurse
*/

#include "../../include/ncurses/ncurses.hpp"

extern "C" Arcade::IGraphic *createLibrary()
{
    return new Arcade::ncursesGraphic();
}

extern "C" void destroyLibrary(Arcade::IGraphic *object)
{
	delete object;
}

Arcade::ncursesGraphic::ncursesGraphic()
{
    initscr();
    noecho();
    curs_set(0);
}

void Arcade::ncursesGraphic::showScore(unsigned int score)
{}

int Arcade::ncursesGraphic::Close()
{
    return 0;
}

int Arcade::ncursesGraphic::Time(clock_t current_time)
{
    return 1;
}

Arcade::ncursesGraphic::~ncursesGraphic() = default;

Arcade::Input Arcade::ncursesGraphic::getInput()
{
   // WINDOW *win;
//   keypad(stdscr, TRUE);
   
//    while (int ch = getch()) {
    switch (int ch = getch()) {
        case 10:
            return Arcade::Input::ENTER;
            break;
        case KEY_UP:
            return Arcade::Input::UP_ARROW;
            break;
        case KEY_DOWN:
            return Arcade::Input::DOWN_ARROW;
            break;
        case KEY_RIGHT:
            return Arcade::Input::RIGHT_ARROW;
            break;
        case KEY_LEFT:
            return Arcade::Input::LEFT_ARROW;
            break;
        case 'q':
            return Arcade::Input::Q_KEY;
            break;
        default:
            return Arcade::Input::NO_INPUT;
        }
//    }
    return Arcade::Input::NO_INPUT;
}

std::string Arcade::ncursesGraphic::getNameLib()
{
    std::string name = "ncurses";

    return name;
}

void Arcade::ncursesGraphic::initMap()
{
    int y = 2;
    int x = 60;
    int j = 0;
    for (int i = 0; i < 21; i++, y++) {
        x = 60;
        for (; j < 19; j++, x++) {
            if (_map[i][j] == '#') attron(COLOR_PAIR(1));
            if (_map[i][j] == 'P') attron(COLOR_PAIR(2));
            if (_map[i][j] == 'G') attron(COLOR_PAIR(3));
            if (_map[i][j] == '.') attron(COLOR_PAIR(4));
            if (_map[i][j] == '$') attron(COLOR_PAIR(4));
            mvaddch(y, x, _map[i][j]);
            if (_map[i][j] == '#') attroff(COLOR_PAIR(1));
            if (_map[i][j] == 'P') attroff(COLOR_PAIR(2));
            if (_map[i][j] == 'G') attroff(COLOR_PAIR(3));
            if (_map[i][j] == '.') attroff(COLOR_PAIR(4));
            if (_map[i][j] == '$') attroff(COLOR_PAIR(4));
        }
        j = 0;
    }
}

void Arcade::ncursesGraphic::initGame(char **map)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    _map = map;
}

void Arcade::ncursesGraphic::display()
{
    return;
}

int Arcade::ncursesGraphic::isGame()
{
    return 1;
}

void Arcade::ncursesGraphic::playMusic()
{

}

void Arcade::ncursesGraphic::closeMusic()
{}

void Arcade::ncursesGraphic::findName(std::vector<std::string> files)
{
	for (int i = 0; i < files.size(); i++) {
		_name = files[i].substr(files[i].find_last_of('_') + 1);
		_name = _name.substr(0, _name.find_last_of('.'));
		if (_name != "ncurses") break;
	}
}

std::string Arcade::ncursesGraphic::color(std::string ret, WINDOW *win)
{
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
	if (_state == 0) {
		if (_tab_game == 0) {
            for (int i = 0; i < _Games.size(); i++) {
                if (i == 0)
                    wattron(win, COLOR_PAIR(3));
                mvwprintw(win, 4 + 2 * i, 45, GameName(_Games[i]).c_str());
                if (i == 0)
                    wattroff(win, COLOR_PAIR(3));
            }
            mvwprintw(win, 4, 60, _name.c_str());
            mvwprintw(win, 6, 60, "NCURSES");
            ret = GameName(_Games[0]);
        }
        else {
            if (_Games.size() == 2) {
                wattron(win, COLOR_PAIR(3));
                mvwprintw(win, 6, 45, GameName(_Games[1]).c_str());
                wattroff(win, COLOR_PAIR(3));
                mvwprintw(win, 4, 45, GameName(_Games[0]).c_str());
                mvwprintw(win, 4, 60, _name.c_str());
                mvwprintw(win, 6, 60, "NCURSES");
                ret = GameName(_Games[1]);
            }
        }
	}
	if (_state == 1) {
        if (_tab_game == 0) {
            wattron(win, COLOR_PAIR(3));
            mvwprintw(win, 4, 60, _name.c_str());
            wattroff(win, COLOR_PAIR(3));
            mvwprintw(win, 6, 60, "NCURSES");
            for (int i = 0; i < _Games.size(); i++)
                mvwprintw(win, 4 + (2 * i), 45, GameName(_Games[i]).c_str());
            endwin();
            ret = _name.c_str();
        }
        else {
            wattron(win, COLOR_PAIR(3));
            mvwprintw(win, 6, 60, "NCURSES");
            wattroff(win, COLOR_PAIR(3));
            mvwprintw(win, 4, 60, _name.c_str());
            for (int i = 0; i < _Games.size(); i++)
                mvwprintw(win, 4 + (2 * i), 45, GameName(_Games[i]).c_str());
            endwin();
            ret = "ncurses";
        }
	}
    return ret;
}

void Arcade::ncursesGraphic::close()
{
    endwin();
}

std::string Arcade::ncursesGraphic::Button(WINDOW *win)
{
    keypad(win, TRUE);
    std::string ret;
    int ch;
    while (ch = wgetch(win)) {
        switch (ch)
        {
        case 10:
            if (ret.size() != 0) {
                endwin();
                return ret;
            }
            break;
        case KEY_UP:
            _tab_game = 0;
            break;
        case KEY_DOWN:
            _tab_game = 1;
            break;
        case KEY_RIGHT:
            _state = 1;
            break;
        case KEY_LEFT:
            _state = 0;
            break;
        case 'q':
            endwin();
            return "NULL";
            break;
        default:
            break;
        }
        ret = color(ret, win);
    }
    return "NULL";
}

std::string Arcade::ncursesGraphic::GameName(std::string files)
{
	std::string name = files.substr(files.find_last_of('_') + 1);
	name = name.substr(0, name.find_last_of('.'));
	return name;
}

std::string Arcade::ncursesGraphic::createWindow(std::vector<std::string> files, std::vector<std::string> filesGame)
{
    initscr();
    noecho();
    curs_set(0);
    _tab_game = 0;
	_state = 0;
    _Games = filesGame;

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax / 1.5, xMax / 2, yMax / 6, xMax / 4);
    box(win, 0, 0);
    findName(files);
    std::string button = "'s' for " + _name;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 1, 45, "GAME");
    mvwprintw(win, 1, 60, "LIBRARY");
    mvwprintw(win, 1, 5, "press:");
    wattroff(win, COLOR_PAIR(1));
    for (int i = 0; i < _Games.size(); i++) {
        if (i == 0)
            wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 4 + 2 * i, 45, GameName(_Games[i]).c_str());
        if (i == 0)
            wattroff(win, COLOR_PAIR(3));
    }
    mvwprintw(win, 4, 60, _name.c_str());
    mvwprintw(win, 6, 60, "NCURSES");
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 5, 5, "'q' for quit");
    wattroff(win, COLOR_PAIR(2));

    std::string ret = Button(win);
    return ret;
}