#ifndef SRC_GAME_WALL_HPP_
#define SRC_GAME_WALL_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"

struct WallConstConfig {
    int x;
    int y;
    int w;
    int h;
    bool reset;
    bool change_x;
    bool change_y;
};

class Wall: public Collider {
    public:
        explicit Wall(const WallConstConfig& cfg);
        const SDL_Rect* get_pos() const override;
        CollisionResult collide(const SDL_Rect& ball_rect) const override;

        ~Wall();

    private:
        bool reset = false;
        bool change_x = false;
        bool change_y = false;
        int x, y, w, h;
        SDL_Rect rect;
};

#endif  // SRC_GAME_WALL_HPP_
