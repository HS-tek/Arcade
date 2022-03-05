#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#include "../IGame.hpp"
#include "Ghost.hpp"
#include "../../Core/include/Core.hpp"


#define NB_LINE 21
#define NB_COL 19



namespace Arcade {
    class Pacman : public Arcade::IGame
    {
        public:
                                Pacman(/* args */);
            virtual             ~Pacman();
            void                move_down();
            void                move_up();
            void                move_left();
            void                move_right();
            int                 checkMove(int i_pos, int j_pos);
            struct t_thing      createmap();
            struct t_thing      get_map();
            int                 getPosPlayer();
            bool                checkGhost();
            int                 setPosPlayer(int x, int y);
            char                **setArray2d();
            void                portal();
            bool                moveAlone(Input save);
            void                eat_ghost();
            
        public :
            unsigned int        getPV() override;
            void                printMap()override;
            char **             getGame(Arcade::Input in)override;
            unsigned int        getScore()override;
            char **             update()override;
            void                init() override;
            void                inputEvent(Arcade::Input input) override;
            void                reset()override;
            
            
        private:
            int             i_pos; 
            int             j_pos;
            int             init_i_pos;
            int             init_j_pos;
            Input           _direction;
            Input           _currentInput;
            clock_t         _run;
            clock_t         current_time;
            int             _score;
            int             _pv = 3;
            bool            _win = false;
            bool            _lose = false;
            bool            _eatable = false;
            Input           _input;
            struct t_thing  thing;
            char **         _array2d;
    };
}

extern "C" void destroyGame(Arcade::IGame *game);
extern "C" Arcade::IGame *createGame();

#endif