#ifndef SRC_GAME_WALL_HPP_
#define SRC_GAME_WALL_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"

class Wall: public Collider {
    public:
        Wall(int x, int y , int w, int h);
        SDL_Rect* get_pos() override;

        ~Wall();

    private:
        int x, y, w, h;
        SDL_Rect rect;
};

#endif  // SRC_GAME_WALL_HPP_
