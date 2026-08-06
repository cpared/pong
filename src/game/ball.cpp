#include "ball.hpp"
#include <iostream>

const Uint8 R = 0;
const Uint8 G = 0;
const Uint8 B = 0;
Ball::Ball(const BallConfig& cfg, int x, int y):
    x(x), y(y), w(cfg.width), h(cfg.height),
    init_x(x), init_y(y),
    rect({x, y, cfg.width, cfg.height}),
    vx(0), vy(cfg.speed),
    speed(cfg.speed) {}

void Ball::render(SDL_Renderer* renderer) {
    rect.y = this->y;
    rect.x = this->x;
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    if (SDL_RenderFillRect(renderer, &rect) != 0) {
        std::cout << "Cannot fill rect, ERR: " << SDL_GetError() << std::endl;
        return;
    }
}

void Ball::on_collide(int delta, const CollisionResult& collision) {
    if (collision.horizontal == HorizontalDirection::Left) {
        this->vx = -speed;
        this->x += delta * this->vx;
        rect.x = this->x;
    } else if (collision.horizontal == HorizontalDirection::Right) {
        this->vx = speed;
        this->x += delta * this->vx;
        rect.x = this->x;
    } else if (collision.reverse_x) {
        if (this->vx == 0) this->vx = speed;
        this->vx *= -1;

        this->x += delta * this->vx;
        rect.x = this->x;
    }

    if (collision.reverse_y) {
        this->vy *= -1;
        this->y += delta * this->vy;
        rect.y = this->y;
    }

    std::cout << "X speed: " << this->vx << std::endl;
}

void Ball::update_pos(int delta) {
    this->y += delta * this->vy;
    rect.y = this->y;
    this->x += delta *this->vx;
    rect.x = this->x;
}

void Ball::reset() {
    this->x = this->init_x;
    this->y = this->init_y;
    rect.x = this->init_x;
    rect.y = this->init_y;
    this->vx = 0;
    this->vy = speed;
}

const SDL_Rect* Ball::get_pos() const {
    return &rect;
}

CollisionResult Ball::collide(const SDL_Rect&) const {
    return {};
}

Ball::~Ball() {}
