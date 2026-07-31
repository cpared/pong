#include "block.hpp"

Block::Block(): x(0), y(0), w(0), h(0), rect({0, 0, 0, 0}), is_visible(false) {}

const SDL_Rect* Block::get_pos() const {
    return &rect;
}

CollisionResult Block::collide(const SDL_Rect& ball_rect) const {
    if (!SDL_HasIntersection(&ball_rect, &rect)) {
        return {};
    }

    return {true, false, false, true};
}

Block::~Block() {}
