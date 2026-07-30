#include "block.hpp"

Block::Block(): x(x), y(y), w(w), h(h) {}

SDL_Rect* Block::get_pos() {
    return &rect;
}


Block::~Block() {}
