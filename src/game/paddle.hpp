#ifndef SRC_GAME_PADDLE_HPP_
#define SRC_GAME_PADDLE_HPP_

#include <SDL2/SDL.h>
#include "./collision/collider.hpp"

class Paddle: public Collider {
    public:
        Paddle(int x, int y , int w, int h);
        void render(SDL_Renderer* renderer);
        void move_left();
        void move_right();
        void stop(int delta);
        void update_pos(int delta, int dir);

        SDL_Rect* get_pos() override;

    private:
        int x, y, w, h;
        SDL_Rect rect;
        SDL_Rect left;
        SDL_Rect middle;
        SDL_Rect right;
        float vx, vy;
        int dir;
};

#endif  // SRC_GAME_PADDLE_HPP_
