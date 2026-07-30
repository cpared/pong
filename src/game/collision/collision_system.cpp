#include "collision_system.hpp"
#include <iostream>

CollisionSystem::CollisionSystem(Ball& ball):
    colliders(),
    ball(ball) {}

void CollisionSystem::add_collider(Collider& collider) {
    colliders.push_back(&collider);
}

void CollisionSystem::check_collision(int delta) {
    SDL_Rect* pos = ball.get_pos();
    for (auto* col : colliders) {
        SDL_Rect* col_pos = col->get_pos();
        if (SDL_HasIntersection(pos, col_pos)) {
            std::cout << "¡Colisión!" << std::endl;
            ball.on_collide(delta, false, true);
        }
    }
}

CollisionSystem::~CollisionSystem() {}
