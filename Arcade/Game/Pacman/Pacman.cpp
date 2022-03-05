/*
** EPITECH PROJECT, 202#
** Pacman
** File description:
** Pacman
*/

#include "Pacman.hpp"

extern "C" Arcade::IGame *createGame()
{
	return new Arcade::Pacman();
}

extern "C" void destroyGame(Arcade::IGame *game)
{
	delete dynamic_cast<Arcade::Pacman *>(game);
}

Arcade::Pacman::Pacman(/* args */)
{ 
    createmap();
    getPosPlayer();
    init_i_pos = i_pos;
    init_j_pos = j_pos;
    current_time = clock();
}

Arcade::Pacman::~Pacman()
{

}

void Arcade::Pacman::init()
{
    
}
void Arcade::Pacman::inputEvent(Arcade::Input input)
{
    switch (input) {
		case Arcade::Input::LEFT_ARROW:
		move_left();
		break;
		case Arcade::Input::RIGHT_ARROW:
		move_right();
		break;
		case Arcade::Input::UP_ARROW:
		move_up();
		break;
		case Arcade::Input::DOWN_ARROW:
		move_down();
		break;
		case Arcade::Input::Q_KEY:
		break;
		case Arcade::Input::NO_INPUT:
		break;
		default :
			return ;
	}
}

void Arcade::Pacman::reset()
{
    createmap();
    getPosPlayer();
    _score = 0;
}

unsigned int Arcade::Pacman::getPV(){
    return this->_pv;
}

struct Arcade::t_thing Arcade::Pacman::createmap()
{
      thing = {
        {   
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','#'},
        {'#','$','#','#','.','#','#','#','.','#','.','#','#','#','.','#','#','$','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','#','#','.','#','.','#','#','#','#','#','.','#','.','#','#','.','#'},
        {'#','.','.','.','.','#','.','.','.','#','.','.','.','#','.','.','.','.','#'},
        {'#','#','#','#','.','#','#','#','.','#','.','#','#','#','.','#','#','#','#'},
        {' ',' ',' ','#','.','#','.','.','.','.','.','.','.','#','.','#',' ',' ',' '},
        {'#','#','#','#','.','#','.','#','#',' ','#','#','.','#','.','#','#','#','#'},
        {'.','.','.','.','.','.','.','#','G',' ','G','#','.','.','.','.','.','.','.'},
        {'#','#','#','#','.','#','.','#','#','#','#','#','.','#','.','#','#','#','#'},
        {' ',' ',' ','#','.','#','.','.','.','.','.','.','.','#','.','#',' ',' ',' '},
        {'#','#','#','#','.','#','.','#','#','#','#','#','.','#','.','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','#'},
        {'#','.','#','#','.','#','#','#','.','#','.','#','#','#','.','#','#','.','#'},
	    {'#','$','.','#','.','.','.','.','.','P','.','.','.','.','.','#','.','$','#'},
	    {'#','#','.','#','.','#','.','#','#','#','#','#','.','#','.','#','.','#','#'},
	    {'#','.','.','.','.','#','.','.','.','#','.','.','.','#','.','.','.','.','#'},
	    {'#','.','#','#','#','#','#','#','.','#','.','#','#','#','#','#','#','.','#'},
	    {'#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
        }};
        _array2d = new char*[NB_LINE+1];
            for (int i = 0; i < NB_LINE+1; ++i) {
              _array2d[i] = new char[NB_COL+1];
            }
            
    return thing;
}

char ** Arcade::Pacman::update()
{
    Ghost *ghost = new Ghost(&thing);
    float interval = ((float)(clock()-current_time)/CLOCKS_PER_SEC);

    if(interval > 0.20f) {
        current_time = clock();
        ghost->moveRandGhostOne();
    }
  delete ghost;
  
  return setArray2d();
}

char **Arcade::Pacman::getGame(Arcade::Input in)
{
    if (in != Arcade::Input::NO_INPUT)
      //std::cout<<clock()<<" ____Input (getgame): "<<in<<std::endl;

    Arcade::Pacman::inputEvent(in);
    /*
    if (_eatable) {
		float delta = current_time - _run;
		std::cout<<"eat capability enable"<<std::endl;
		if (delta / CLOCKS_PER_SEC > 10.f)
			_eatable = false;
			std::cout<<"eat capability diseable"<<std::endl;
    }*/
    
    if (_lose == true){
    std::cout<<"YOU LOSE LOSERRRR GO DIEEEEEEEE"<<std::endl;
    }else if (_pv <= 2)
    std::cout<<"pv: "<<_pv<<std::endl;

    return  setArray2d();
}

unsigned int Arcade::Pacman::getScore()
{
    return _score;
}

char **Arcade::Pacman::setArray2d()
{
    for (int i = 0; i < NB_LINE; i++) {   
        for (int j = 0; j < NB_COL; j++) {   
            _array2d[i][j] = thing.map[i][j];
            }
        _array2d[i][NB_COL]= '\0';
    }
    return _array2d;
}


struct Arcade::t_thing  Arcade::Pacman::get_map()
{
	return thing;
}

int Arcade::Pacman::getPosPlayer()
{
	int i,j = 0;
	for (i = 0; i < NB_LINE; i++)
    {
        for (j = 0; j < NB_COL; j++)
        {
            if (thing.map[i][j] == 'P')
            {
            j_pos = j;
            i_pos = i;
            break;
			}
        }
    }
    return 0;
}


void Arcade::Pacman::eat_ghost(){
    if(_eatable)
    {
        if(thing.map[i_pos][j_pos] == 'G'){
            thing.map[i_pos][j_pos] = 'P';
            _score += 100;
        }
    }else if (!_eatable){
        if(thing.map[i_pos][j_pos] == 'G'){
            _pv -= 1;
            if(_pv == 0)
            _lose = true;
        }
    }
}

void Arcade::Pacman::move_right()
{
	if (((j_pos+1)< NB_COL) && (thing.map[i_pos][j_pos+1] != '#'))
    {
        if(thing.map[i_pos][j_pos+1] == '.'){
            _score += 10;
        }
        if(thing.map[i_pos][j_pos+1] == '$'){
            _score += 50;
            _eatable = true;
            
        }
        thing.map[i_pos][j_pos] = ' ';
        thing.map[i_pos][j_pos+1] = 'P';
        j_pos = j_pos+1;
    }
    if (i_pos == 9 && j_pos == 19)
    {
        thing.map[i_pos][19] = ' ';
        thing.map[i_pos][0] = 'P';
        j_pos = 0;
    }
}

void Arcade::Pacman::move_left()
{

	if (((j_pos-1) >= 0) && (thing.map[i_pos][j_pos-1] != '#'))
    {
        if(thing.map[i_pos][j_pos-1] == '.'){
            _score += 10;
        }
        if(thing.map[i_pos][j_pos-1] == '$'){
            _score += 50;
            _eatable = true;
        }
            thing.map[i_pos][j_pos] = ' ';
            thing.map[i_pos][j_pos-1] = 'P';
            j_pos = j_pos-1;
    }
    if (i_pos == 9 && j_pos == 0)
    {
        thing.map[i_pos][j_pos] = ' ';
        thing.map[i_pos][NB_COL-1] = 'P';
        j_pos = 18;
    }
    
}
void Arcade::Pacman::move_up()
{
	if (((i_pos-1) >= 0) && (thing.map[i_pos-1][j_pos] != '#'))
    {
        if(thing.map[i_pos-1][j_pos] == '.'){
            _score += 10;
        }
        if(thing.map[i_pos-1][j_pos] == '$'){
            _score += 50;
            _eatable = true;
        }
            thing.map[i_pos][j_pos] = ' ';
            thing.map[i_pos-1][j_pos] = 'P';
            i_pos = i_pos-1;
    }
}
void Arcade::Pacman::move_down()
{
	if (((i_pos+1)< NB_LINE) && (thing.map[i_pos+1][j_pos] != '#'))
    {
        if(thing.map[i_pos+1][j_pos] == '.'){
            _score += 10;
        }
        if(thing.map[i_pos+1][j_pos] == '$'){
            _score += 50;
            _eatable = true;
        }
            thing.map[i_pos][j_pos] = ' ';
            thing.map[i_pos+1][j_pos] = 'P';
            i_pos = i_pos+1;
    }
}


void Arcade::Pacman::printMap()
{
    int i, j = 0;
    for (i = 0; i < NB_LINE; i++)
    {   
        for (j = 0; j < NB_COL; j++)
        {
            std::cout << thing.map[i][j];
        }
        std::cout << std::endl;
    }
}

