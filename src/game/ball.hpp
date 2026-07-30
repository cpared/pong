#ifndef SRC_GAME_BALL_HPP_
#define SRC_GAME_BALL_HPP_

#include <SDL2/SDL.h>

class Ball {
    public:
        Ball(int x, int y , int w, int h);
        void render(SDL_Renderer* renderer);
        void update_pos(int delta);
        void on_collide(int delta, bool collide_x, bool collide_y);
        SDL_Rect* get_pos();
        ~Ball();

    private:
        int x, y, w, h;
        SDL_Rect rect;
        float vx, vy;
};

#endif  // SRC_GAME_BALL_HPP_
