#ifndef SRC_GAME_GAME_HPP_
#define SRC_GAME_GAME_HPP_

#include <SDL2/SDL.h>
#include <vector>
#include "paddle.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "./collision/collision_system.hpp"
#include "../config/game_config.hpp"

class Game {
    public:
        explicit Game(const GameConfig& cfg);
        void render(SDL_Renderer* renderer);
        void run(int delta, int dir);
        ~Game();

    private:
        Paddle paddle;
        Ball ball;
        Wall top_wall, buttom_wall, left_wall, rigth_wall;
        std::vector<Collider*> colliders;
        CollisionSystem collision_system;
};

#endif  // SRC_GAME_GAME_HPP_
