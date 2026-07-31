#include "wall.hpp"

Wall::Wall(int x, int y , int w, int h, bool reset, bool change_x, bool change_y):
    reset(reset),
    change_x(change_x),
    change_y(change_y),
    x(x), y(y), w(w), h(h),
    rect({x, y, w, h}) {}

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
