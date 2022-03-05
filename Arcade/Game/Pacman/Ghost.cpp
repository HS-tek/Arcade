/*
** EPITECH PROJECT, 202#
** Pacman-Ghost
** File description:
** Pacman-Ghost
*/

#include "Ghost.hpp"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <functional>

#define size 10


bool running = true;
int Gamespeed = 100;

Arcade::Ghost::Ghost(struct t_thing* obj)
{
    thing = obj;
    getPosGhost();
    init_i_pos_one = i_pos_one;
    init_j_pos_one = j_pos_one;
}

Arcade::Ghost::~Ghost()
{
}

int Arcade::Ghost::getPosGhost()
{
	int i,j = 0;
	j_pos_one = -1;
    i_pos_one = -1;
    i_pos_two = -1;
    j_pos_two = -1;
	for (i = 0; i < NB_LINE; i++)
    {
        for (j = 0; j < NB_COL; j++)
        {
            if (thing->map[i][j] == 'G')
            {
                if(j_pos_one == -1)
                {
                    j_pos_one = j;
                    i_pos_one = i;
                }else if(j_pos_two == -1)
                {
                    i_pos_two = i;
                    j_pos_two = j;
                    break;
                }             
			}
        }
    }
    return (0);
}
bool Arcade::Ghost::move_right(int what_ghost)
{
    
    if (what_ghost == 1) {        
        if (((j_pos_one+1)< NB_COL) && (thing->map[i_pos_one][j_pos_one+1] != '#')&& (thing->map[i_pos_one][j_pos_one+1] != 'G')) 
        {
            if(thing->map[i_pos_one][j_pos_one+1] == '.') {   
                thing->map[i_pos_one][j_pos_one] = '.';
                thing->map[i_pos_one][j_pos_one+1] = 'G';
                j_pos_one = j_pos_one+1;
                return true;
            }else{
                thing->map[i_pos_one][j_pos_one] = ' ';
                thing->map[i_pos_one][j_pos_one+1] = 'G';
                j_pos_one = j_pos_one+1;
                return true;
                }
        }
        return false;
    } 
    else if (what_ghost == 2) {       
        if (((j_pos_two+1)< NB_COL) && (thing->map[i_pos_two][j_pos_two+1] != '#')&& (thing->map[i_pos_two][j_pos_two+1] != 'G')) 
        {
            if(thing->map[i_pos_two][j_pos_two+1] == '.')
            {
                thing->map[i_pos_two][j_pos_two] = '.';
                thing->map[i_pos_two][j_pos_two+1] = 'G';
                j_pos_two = j_pos_two+1;
                return true;
            }else {
                thing->map[i_pos_two][j_pos_two] = ' ';
                thing->map[i_pos_two][j_pos_two+1] = 'G';
                j_pos_two = j_pos_two+1;
                return true;
                }
        }return false;
    }
    return false;
}
bool Arcade::Ghost::move_left(int what_ghost)
{
    if (what_ghost == 1){
        if (((j_pos_one-1) >= 0) && (thing->map[i_pos_one][j_pos_one-1] != '#')&& (thing->map[i_pos_one][j_pos_one-1] != 'G'))
        {
            if(thing->map[i_pos_one][j_pos_one-1] == '.'){
                thing->map[i_pos_one][j_pos_one] = '.';
                thing->map[i_pos_one][j_pos_one-1] = 'G';
                j_pos_one = j_pos_one-1;
                return true;
            }else
                {thing->map[i_pos_one][j_pos_one] = ' ';
                thing->map[i_pos_one][j_pos_one-1] = 'G';
                j_pos_one = j_pos_one-1;
                return true;}
        }return false;
    }
    else if (what_ghost == 2) {
        
        if (((j_pos_two-1) >= 0) && (thing->map[i_pos_two][j_pos_two-1] != '#')&& (thing->map[i_pos_two][j_pos_two-1] != 'G'))
        {
            if(thing->map[i_pos_two][j_pos_two-1] == '.'){
                thing->map[i_pos_two][j_pos_two] = '.';
                thing->map[i_pos_two][j_pos_two-1] = 'G';
                j_pos_two = j_pos_two-1;
                return true;
            } else {
                thing->map[i_pos_two][j_pos_two] = ' ';
                thing->map[i_pos_two][j_pos_two-1] = 'G';
                j_pos_two = j_pos_two-1;
                return true;
            }
        }return false;
    }
    return false;
}
bool Arcade::Ghost::move_up(int what_ghost)
{
    if (what_ghost == 1){
        
        if (((i_pos_one-1) >= 0) && (thing->map[i_pos_one-1][j_pos_one] != '#')&& (thing->map[i_pos_one-1][j_pos_one] != 'G'))
        {
            if(thing->map[i_pos_one-1][j_pos_one] == '.'){
                thing->map[i_pos_one][j_pos_one] = '.';
                thing->map[i_pos_one-1][j_pos_one] = 'G';
                i_pos_one = i_pos_one-1;
                return true;
            }else {
                thing->map[i_pos_one][j_pos_one] = ' ';
                thing->map[i_pos_one-1][j_pos_one] = 'G';
                i_pos_one = i_pos_one-1;
                return true;
                }
        }return false;
    }
    else if (what_ghost == 2) {
        if (((i_pos_two-1) >= 0) && (thing->map[i_pos_two-1][j_pos_two] != '#')&& (thing->map[i_pos_two-1][j_pos_two] != 'G'))
        {
            if(thing->map[i_pos_two-1][j_pos_two] == '.')
            {
                thing->map[i_pos_two][j_pos_two] = '.';
                thing->map[i_pos_two-1][j_pos_two] = 'G';
                i_pos_two = i_pos_two-1;
                return true;
            }else {
                thing->map[i_pos_two][j_pos_two] = ' ';
                thing->map[i_pos_two-1][j_pos_two] = 'G';
                i_pos_two = i_pos_two-1;
                return true;}
        }return false;
    }
    return false;
}

bool Arcade::Ghost::move_down(int what_ghost)
{
    if (what_ghost == 1){
        
        if (((i_pos_one+1)<NB_LINE) && (thing->map[i_pos_one+1][j_pos_one] != '#') && (thing->map[i_pos_one+1][j_pos_one] != 'G'))
        {
            if( thing->map[i_pos_one+1][j_pos_one] == '.')
            {
                thing->map[i_pos_one][j_pos_one] = '.';
                thing->map[i_pos_one+1][j_pos_one] = 'G';
                i_pos_one = i_pos_one+1;
                return true;
            }else{
                thing->map[i_pos_one][j_pos_one] = ' ';
                thing->map[i_pos_one+1][j_pos_one] = 'G';
                i_pos_one = i_pos_one+1;
                return true;}
        }return false;
    }
    else if (what_ghost == 2) {
        
        if (((i_pos_two+1)<NB_LINE) && (thing->map[i_pos_two+1][j_pos_two] != '#') && (thing->map[i_pos_two+1][j_pos_two] != 'G'))
        {
            if(thing->map[i_pos_two+1][j_pos_two] == '.'){
                thing->map[i_pos_two][j_pos_two] = '.';
                thing->map[i_pos_two+1][j_pos_two] = 'G';
                i_pos_two = i_pos_two+1;
                return true;
            }else{
                thing->map[i_pos_two][j_pos_two] = ' ';
                thing->map[i_pos_two+1][j_pos_two] = 'G';
                i_pos_two = i_pos_two+1;
                return true;}
        }return false;
    }
    return false;
}

void Arcade::Ghost::printMap()
{
    int i, j = 0;
    for (i = 0; i < NB_LINE; i++)
    {
        for (j = 0; j < NB_COL; j++)
        {
//            std::cout << thing->map[i][j];
        }        
    }
}

void Arcade::Ghost::moveRandGhostOne()
{
    std::srand(std::clock());
    int i = 0;
    int rand_time=1;
    std::srand(std::clock());
    
    for(i = 0; i <= rand_time ; i++) {
        std::srand(std::clock());
        int random = std::rand()%4;
        findMove(1, random);
        findMove(2, random);
    }
}

void Arcade::Ghost::findMove(int rand_ghost, int random)
{
    	if (random == 0) {
    		if (!move_up(rand_ghost))
    		  if(!move_down(rand_ghost))
    		    if(!move_right(rand_ghost))
    		      move_left(rand_ghost);
        }
    	if (random == 1) {
    		if (!move_right(rand_ghost))
    		  if(!move_left(rand_ghost))
    		    if(!move_down(rand_ghost))
    		      move_up(rand_ghost);
        }
    	if (random == 2) {
    		if (!move_left(rand_ghost))
    		  if(!move_up(rand_ghost))
    		    if(!move_right(rand_ghost))
    		      move_down(rand_ghost);
        }
    	if (random == 3) {
    		if (!move_down(rand_ghost))
    		  if(!move_right(rand_ghost))
    		    if(!move_left(rand_ghost))
    		      move_up(rand_ghost);
    	}
}
