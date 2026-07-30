#include "game.hpp"
#include <iostream>
#include <functional>

const int FRAME = 20;
Game::Game():
    paddle(800 / 2, 500, 100, 30),
    ball(800 / 2, 600 / 2, 10, 10),

    // Init walls
    top_wall(0, 0, 800, 10),
    buttom_wall(0, 600 - 10, 800, 10),
    left_wall(0, 0, 10, 600),
    rigth_wall(800 - 10, 0, 10, 600),

    // Init collision system
    collision_system(ball) {
        collision_system.add_collider(paddle);
        collision_system.add_collider(top_wall);
        collision_system.add_collider(buttom_wall);
        collision_system.add_collider(left_wall);
        collision_system.add_collider(rigth_wall);
    }

void Game::run(int delta, int dir) {
    ball.update_pos(delta);
    paddle.update_pos(delta, dir);
    collision_system.check_collision(delta);
}

void Game::render(SDL_Renderer* renderer) {
    paddle.render(renderer);
    ball.render(renderer);
}

Game::~Game() {}
