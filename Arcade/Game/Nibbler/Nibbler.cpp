/*
** EPITECH PROJECT, 202#
** Nibbler
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

//extern "C"{void printMap();}

extern "C" Arcade::IGame *createGame()
{
	return new Arcade::Nibbler();
}

extern "C" void destroyGame(Arcade::IGame *game)
{
	delete dynamic_cast<Arcade::Nibbler *>(game);
}

Arcade::Nibbler::Nibbler(/* args */)
{ 
    createmap();
    getPosPlayer();
    init_i_pos = i_pos;
    init_j_pos = j_pos;
    struct  position pos = {i_pos, j_pos};
    pos_player.push_back(pos);
    current_time = clock();
}

Arcade::Nibbler::~Nibbler()
{

}

void Arcade::Nibbler::init()
{
    
}
void Arcade::Nibbler::inputEvent(Arcade::Input input)
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
    


void Arcade::Nibbler::reset()
{
    createmap();
    getPosPlayer();
    _lose = false;
    _win = false;
    _score = 0;
    init_i_pos = i_pos;
    init_j_pos = j_pos;
    struct  position pos = {i_pos, j_pos};
    pos_player.push_back(pos);
    current_time = clock();
}

unsigned int Arcade::Nibbler::getPV(){
    return this->_pv;
}

struct Arcade::t_thing Arcade::Nibbler::createmap()
{
      thing = {
        {   
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','$',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','$','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','$','#'},
        {'#',' ',' ',' ','$',' ',' ',' ',' ','#',' ',' ','$',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#',' ','#',' ',' ',' ','#',' ','#','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','$',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ','#'},
        {'#',' ',' ','$',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ','$',' ',' ','#'},
        {'#',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ','#'},
	    {'#','$','#',' ','#',' ',' ',' ',' ','P',' ',' ',' ',' ','#',' ','#','$','#'},
	    {'#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#'},
	    {'#',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},
	    {'#',' ',' ','#','#','#',' ',' ','#','#','#',' ',' ','#','#','#',' ',' ','#'},
	    {'#',' ',' ',' ','$',' ',' ',' ',' ','$',' ',' ',' ',' ','$',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
        }};
        _array2d = new char*[NB_LINE+1];
            for (int i = 0; i < NB_LINE+1; ++i) {
              _array2d[i] = new char[NB_COL+1];
            }
            
    return thing;
}

char ** Arcade::Nibbler::update()
{
    float interval = ((float)(clock()-current_time)/CLOCKS_PER_SEC);

    if(interval > 0.20f) {
        current_time = clock();
    }
  
  return setArray2d();
}

void	Arcade::Nibbler::popFruit()
{

}


char **Arcade::Nibbler::getGame(Arcade::Input in)
{
    if (in != Arcade::Input::NO_INPUT){
        _last_input = in;
    }
    float interval = ((float)(clock()-current_time)/CLOCKS_PER_SEC);
    current_time = clock();
    
    Arcade::Nibbler::inputEvent(_last_input);
        current_time = clock();

    if (_lose == true){
    std::cout<<"YOU LOSE"<<std::endl;
    reset();
    }
    return  setArray2d();
}

unsigned int Arcade::Nibbler::getScore()
{
    return _score;
}

char **Arcade::Nibbler::setArray2d()
{
        for (int i = 0; i < NB_LINE; i++)
        {   
            for (int j = 0; j < NB_COL; j++)
            {   
                _array2d[i][j] = thing.map[i][j];
            }
            _array2d[i][NB_COL]= '\0';
        }
    return _array2d;
}


struct Arcade::t_thing  Arcade::Nibbler::get_map()
{
	return thing;
}

int Arcade::Nibbler::getPosPlayer()
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

void Arcade::Nibbler::move_right()
{

    int ii_pos = 0;
    int jj_pos = 0;

    if (((pos_player[0].j+1)>= NB_COL) || (thing.map[pos_player[0].i][pos_player[0].j+1] == '#'))
    {
        _lose = true;
        return;
    }          
    ii_pos = pos_player[0].i;
    jj_pos = pos_player[0].j;
    if(thing.map[ii_pos][jj_pos+1] == '$') {
        _score += 50;
        struct  position pos = {ii_pos, jj_pos};
        pos_player.push_back(pos);
    }
    thing.map[ii_pos][jj_pos+1] = 'P';
    thing.map[ii_pos][jj_pos] = ' ';
    pos_player[0].j = jj_pos+1;  

    for(int i=1; i< pos_player.size(); i++) {

        thing.map[pos_player[i].i][pos_player[i].j] = ' ';

        int tmp_i = pos_player[i].i;
        int tmp_j = pos_player[i].j;
        pos_player[i].i = ii_pos; 
        pos_player[i].j = jj_pos;    
        ii_pos = tmp_i;
        jj_pos = tmp_j;

        thing.map[pos_player[i].i][pos_player[i].j] = 'P';
    }
}

void Arcade::Nibbler::move_left()
{
    int ii_pos = 0;
    int jj_pos = 0;

    if (((pos_player[0].j-1)< 0) || (thing.map[pos_player[0].i][pos_player[0].j-1] == '#'))
    {
        _lose = true;
        return;
    }           
    ii_pos = pos_player[0].i;
    jj_pos = pos_player[0].j;
    if(thing.map[ii_pos][jj_pos-1] == '$') {
        _score += 50;
        struct  position pos = {ii_pos, jj_pos};
        pos_player.push_back(pos);
    }
    thing.map[ii_pos][jj_pos-1] = 'P';
    thing.map[ii_pos][jj_pos] = ' ';
    pos_player[0].j = jj_pos-1;  

    for(int i=1; i< pos_player.size(); i++) {

        thing.map[pos_player[i].i][pos_player[i].j] = ' ';

        int tmp_i = pos_player[i].i;
        int tmp_j = pos_player[i].j;
        pos_player[i].i = ii_pos; 
        pos_player[i].j = jj_pos;    
        ii_pos = tmp_i;
        jj_pos = tmp_j;

        thing.map[pos_player[i].i][pos_player[i].j] = 'P';
    }
}

void Arcade::Nibbler::move_up()
{

    int ii_pos = 0;
    int jj_pos = 0;

    if (((pos_player[0].i-1)< 0) || (thing.map[pos_player[0].i-1][pos_player[0].j] == '#')) {
        _lose = true;
        return;
    }
    ii_pos = pos_player[0].i;
    jj_pos = pos_player[0].j;
    if(thing.map[ii_pos-1][jj_pos] == '$') {
            _score += 50;
            struct  position pos = {ii_pos, jj_pos};
            pos_player.push_back(pos);
    }
    thing.map[ii_pos-1][jj_pos] = 'P';
    thing.map[ii_pos][jj_pos] = ' ';
    pos_player[0].i = ii_pos-1;  

    for(int i=1; i< pos_player.size(); i++) {

        thing.map[pos_player[i].i][pos_player[i].j] = ' ';

        int tmp_i = pos_player[i].i;
        int tmp_j = pos_player[i].j;
        pos_player[i].i = ii_pos; 
        pos_player[i].j = jj_pos;    
        ii_pos = tmp_i;
        jj_pos = tmp_j;

        thing.map[pos_player[i].i][pos_player[i].j] = 'P';
    }
}
void Arcade::Nibbler::move_down()
{
    int ii_pos = 0;
    int jj_pos = 0;

    if (((pos_player[0].i+1)>= NB_LINE) || (thing.map[pos_player[0].i+1][pos_player[0].j] == '#'))
    {
        _lose = true;
        return;
    }    

    ii_pos = pos_player[0].i;
    jj_pos = pos_player[0].j;
    if(thing.map[ii_pos+1][jj_pos] == '$') {
        _score += 50;
        struct  position pos = {ii_pos, jj_pos};
        pos_player.push_back(pos);
    }
    thing.map[ii_pos+1][jj_pos] = 'P';
    thing.map[ii_pos][jj_pos] = ' ';
    pos_player[0].i = ii_pos+1;  

    for(int i=1; i< pos_player.size(); i++) {

        thing.map[pos_player[i].i][pos_player[i].j] = ' ';

        int tmp_i = pos_player[i].i;
        int tmp_j = pos_player[i].j;
        pos_player[i].i = ii_pos; 
        pos_player[i].j = jj_pos;    
        ii_pos = tmp_i;
        jj_pos = tmp_j;

        thing.map[pos_player[i].i][pos_player[i].j] = 'P';
    }
}


void Arcade::Nibbler::printMap()
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

