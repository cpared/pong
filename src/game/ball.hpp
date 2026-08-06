#ifndef SRC_GAME_BALL_HPP_
#define SRC_GAME_BALL_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"
#include "../config/game_config.hpp"

class Ball: public Collider {
    public:
        Ball(const BallConfig& cfg, int x, int y);
        void render(SDL_Renderer* renderer);
        void update_pos(int delta);
        void on_collide(int delta, const CollisionResult& collision);
        void reset();
        const SDL_Rect* get_pos() const override;
        CollisionResult collide(const SDL_Rect& ball_rect) const override;

        ~Ball();

    private:
        bool is_reset = false;
        int x, y, w, h;
        int init_x, init_y;
        SDL_Rect rect;
        float vx, vy;
        float speed;
};

#endif  // SRC_GAME_BALL_HPP_
