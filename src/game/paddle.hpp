#ifndef SRC_GAME_PADDLE_HPP_
#define SRC_GAME_PADDLE_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"
#include "../config/game_config.hpp"

class Paddle: public Collider {
    public:
        Paddle(const PaddleConfig& cfg, int x, int y, int window_width);
        void render(SDL_Renderer* renderer);
        void move_left();
        void move_right();
        void stop(int delta);
        void update_pos(int delta, int dir);

        const SDL_Rect* get_pos() const override;
        CollisionResult collide(const SDL_Rect& ball_rect) const override;

    private:
        int x, y, w, h;
        SDL_Rect rect;
        SDL_Rect left;
        SDL_Rect right;
        float vx, vy;
        float speed;
        int dir;
        int window_width;
};

#endif  // SRC_GAME_PADDLE_HPP_
