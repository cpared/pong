#ifndef SRC_GAME_COLLISION_COLLIDER_HPP_
#define SRC_GAME_COLLISION_COLLIDER_HPP_

#include <SDL2/SDL.h>

class Collider {
    public:
        virtual ~Collider() = default;
        virtual SDL_Rect* get_pos() = 0;
};

#endif  // SRC_GAME_COLLISION_COLLIDER_HPP_
