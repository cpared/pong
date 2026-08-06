#include "wall.hpp"

Wall::Wall(const WallConstConfig& cfg):
    reset(cfg.reset),
    change_x(cfg.change_x),
    change_y(cfg.change_y),
    x(cfg.x), y(cfg.y), w(cfg.w), h(cfg.h),
    rect({cfg.x, cfg.y, cfg.w, cfg.h}) {}

const SDL_Rect* Wall::get_pos() const {
    return &rect;
}

CollisionResult Wall::collide(const SDL_Rect& ball_rect) const {
    if (!SDL_HasIntersection(&ball_rect, &rect)) {
        return {};
    }

    return {true, reset, change_x, change_y};
}

Wall::~Wall() {}
