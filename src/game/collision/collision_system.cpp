#include "collision_system.hpp"
#include <iostream>

CollisionSystem::CollisionSystem(Ball& ball):
    colliders(),
    ball(ball) {}

void CollisionSystem::add_collider(Collider& collider) {
    colliders.push_back(&collider);
}

CollisionResult CollisionSystem::collide(const Collider& collider) const {
    return collider.collide(*ball.get_pos());
}

CollisionSystem::~CollisionSystem() {}
