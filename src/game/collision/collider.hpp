#ifndef SRC_GAME_COLLISION_COLLIDER_HPP_
#define SRC_GAME_COLLISION_COLLIDER_HPP_

#include <SDL2/SDL.h>

enum class HorizontalDirection {
    Keep,
    Left,
    Right,
};

struct CollisionResult {
    bool hit = false;
    bool reset_ball = false;
    bool reverse_x = false;
    bool reverse_y = false;
    HorizontalDirection horizontal = HorizontalDirection::Keep;
};

class Collider {
    public:
        virtual ~Collider() = default;
        virtual const SDL_Rect* get_pos() const = 0;
        virtual CollisionResult collide(const SDL_Rect& ball_rect) const = 0;
};

#endif  // SRC_GAME_COLLISION_COLLIDER_HPP_
