#include "ball.hpp"
#include <iostream>

const Uint8 R = 0;
const Uint8 G = 0;
const Uint8 B = 0;
const float SPEED = 0.2;

Ball::Ball(int x, int y , int w, int h): x(x), y(y), w(w), h(h),
    rect({x, y, w, h}),
    vx(0), vy(SPEED) {}

void Ball::render(SDL_Renderer* renderer) {
    rect.y = this->y;
    rect.x = this->x;
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    if (SDL_RenderFillRect(renderer, &rect) != 0) {
        std::cout << "Cannot fill rect, ERR: " << SDL_GetError() << std::endl;
        return;
    }
}

void Ball::on_collide(int delta, bool collide_x, bool collide_y) {
    if (collide_x)
        this->vx *= -1;

    if (collide_y)
        this->vy *= -1;

    this->y += delta * this->vy;
    rect.y = this->y;
}

void Ball::update_pos(int delta) {
    this->y += delta * this->vy;
    rect.y = this->y;
}

SDL_Rect* Ball::get_pos() {
    return &rect;
}

Ball::~Ball() {}
