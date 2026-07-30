#include "wall.hpp"

Wall::Wall(int x, int y , int w, int h): x(x), y(y), w(w), h(h),
    rect({x, y, w, h}) {}

SDL_Rect* Wall::get_pos() {
    return &rect;
}

Wall::~Wall() {}
