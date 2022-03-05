#ifndef __NIBBLER_HPP__
#define __NIBBLER_HPP__

#include "../IGame.hpp"
#include "../../Core/include/Core.hpp"


#define NB_LINE 21
#define NB_COL 19



namespace Arcade {

    typedef struct player_s {
	int 		pos_col;
	int 		pos_row;
    } player_s;
    
    typedef struct position
    {
        int i;
        int j;
    }position;
    
    
    struct t_thing {
        char map[NB_LINE][NB_COL];
    };
    class Nibbler : public Arcade::IGame
    {        
        public:
                                Nibbler();
            virtual             ~Nibbler();
            struct t_thing      createmap();
            struct t_thing      get_map();
            int                 getPosPlayer();
            bool                checkGhost();
            void                popFruit();
            int                 setPosPlayer(int x, int y);
            char **             setArray2d();
            
            void                move_down();
            void                move_up();
            void                move_left();
            void                move_right();
            int                 checkMove(int i_pos, int j_pos);
            
        public : 
            void                init() override;
            void                inputEvent(Arcade::Input input) override;
            void                reset()override;
            char **             getGame(Arcade::Input in)override;
            unsigned int        getScore()override;
            char **             update()override;
            unsigned int        getPV() override;
            void                printMap()override;
        
        private:
            Input                   _input;
            struct t_thing          thing;
            std::vector<position>   pos_player;
            char **                 _array2d;
            int                     init_i_pos;
            int                     init_j_pos;
            Input                   _direction;
            Input                   _currentInput;
            Input                   _last_input;
            clock_t                 _run;
            clock_t                 current_time;
            int                     _score;
            int                     _pv = 3;
            bool                    _win = false;
            bool                    _lose = false;
            bool                    _eatable = false;
            int                     i_pos;
            int                     j_pos;
    };
}

extern "C" void destroyGame(Arcade::IGame *game);
extern "C" Arcade::IGame *createGame();

#endif