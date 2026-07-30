#ifndef SRC_GAME_BLOCK_HPP_
#define SRC_GAME_BLOCK_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"

class Block: public Collider {
    public:
        Block();
        SDL_Rect* get_pos() override;
        ~Block();

    private:
        int x, y, w, h;
        SDL_Rect rect;
        bool is_visible;
};

#endif  // SRC_GAME_BLOCK_HPP_
