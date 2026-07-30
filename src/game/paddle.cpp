#include "paddle.hpp"
#include <iostream>

const Uint8 R = 0;
const Uint8 G = 0;
const Uint8 B = 0;
const float SPEED = 1;

Paddle::Paddle(int x, int y, int w, int h): x(x), y(y), w(w), h(h),
    rect({x, y, w, h}),
    left({x, y, w / 3, h}),
    middle({x + (w / 3), y, w - (w / 3) - (w / 3), h }),
    right({x + w - (w / 3), y, (w / 3), h}),
    vx(0), vy(0),
    dir(0) {}

void Paddle::render(SDL_Renderer* renderer) {
    rect.x = this->x;
    rect.y = this->y;
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    if (SDL_RenderFillRect(renderer, &rect) != 0) {
        std::cout << "Cannot fill rect, ERR: " << SDL_GetError() << std::endl;
        return;
    }
}

void Paddle::move_left() {
    dir = -1;
    this->vx = SPEED;
}

void Paddle::move_right() {
    dir = 1;
    this->vx = -SPEED;
}

void Paddle::update_pos(int delta, int dir) {
    if (dir == -1) move_left();

    if (dir == 1) move_right();

    if (dir == 0) stop(delta);

    if (this->x <= 0)
        this->x = 0;
    if (this->x >= 800 - w)
        this->x = 800 - w;

    this->x -= delta * this->vx;
    rect.x = this->x;
}

void Paddle::stop(int delta) {
    if (dir == -1) {
        this->vx += delta;
        if (this->vx > 0) {
            dir = 0;
            this->vx = 0;
        }
    }

    if (dir == 1) {
        this->vx -= delta;
        if (this->vx < 0) {
            dir = 0;
            this->vx = 0;
        }
    }
}

SDL_Rect* Paddle::get_pos() {
    return &rect;
}
