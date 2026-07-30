#ifndef SRC_GAME_COLLISION_COLLISION_SYSTEM_HPP_
#define SRC_GAME_COLLISION_COLLISION_SYSTEM_HPP_

#include <vector>
#include "collider.hpp"
#include "../ball.hpp"

class CollisionSystem {
    private:
        std::vector<Collider*> colliders;
        Ball& ball;

    public:
        explicit CollisionSystem(Ball& ball);
        void add_collider(Collider& collider);
        void check_collision(int delta);
        ~CollisionSystem();
};

#endif  // SRC_GAME_COLLISION_COLLISION_SYSTEM_HPP_
