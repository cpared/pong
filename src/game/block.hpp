#ifndef SRC_GAME_BLOCK_HPP_
#define SRC_GAME_BLOCK_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"

class Block: public Collider {
    public:
        Block();
        const SDL_Rect* get_pos() const override;
        CollisionResult collide(const SDL_Rect& ball_rect) const override;
        ~Block();

    private:
        bool reset = false;
        int x, y, w, h;
        SDL_Rect rect;
        bool is_visible;
};

#endif  // SRC_GAME_BLOCK_HPP_
