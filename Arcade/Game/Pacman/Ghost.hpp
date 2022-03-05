#ifndef __GHOST_HPP__
#define __GHOST_HPP__

#include "../IGame.hpp"
#include "../Clock.hpp"
//#include "Pacman.hpp"
#include "../../Core/include/Core.hpp"

#define NB_LINE 21
#define NB_COL 19
/*
typedef struct player_s {
	int 		pos_col;
	int 		pos_row;
} player_s;

struct t_thing {
    char map[NB_LINE][NB_COL];
};*/

namespace Arcade {

    typedef struct player_s {
	int 		pos_col;
	int 		pos_row;
    } player_s;
    
    struct t_thing {
        char map[NB_LINE][NB_COL];
    };
    class Ghost
    {
            private:
                /* data */
            public:
                Ghost(struct t_thing*);
                ~Ghost();
                bool                move_down(int what_ghost);
                bool                move_up(int what_ghost);
                bool                move_left(int what_ghost);
                bool                move_right(int what_ghost);
                int                 checkMove(int i_pos, int j_pos);
                struct t_thing      get_map();
                int                 getPosGhost();
                int                 setPosPlayer(int x, int y);
                void                printMap();
                void                moveRandGhostOne();
                void                findMove(int rand_ghost, int random);
                
            private:
                struct t_thing  *thing;
                int             init_i_pos_one;
                int             init_j_pos_one;
                int             init_i_pos_two;
                int             init_j_pos_two;
                int             i_pos_one; 
                int             j_pos_one;
                int             i_pos_two;
                int             j_pos_two;
    };
}


#endif /*end of Ghost.hpp*/