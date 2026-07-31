#include "game.hpp"
#include <iostream>
#include <functional>

const int FRAME = 20;
Game::Game(const GameConfig& cfg):
    paddle(800 / 2, 500, 100, 30),
    ball(800 / 2, 600 / 2, 10, 10),

    // Init walls
    top_wall(0, 0, 800, 10, false, false, true),
    buttom_wall(0, 600 - 10, 800, 10, true, false, false),
    left_wall(0, 0, 10, 600, false, true, false),
    rigth_wall(800 - 10, 0, 10, 600, false, true, false),

    colliders {
        &paddle,
        &top_wall,
        &buttom_wall,
        &left_wall,
        &rigth_wall,
    },
    collision_system(ball) {}

void Game::run(int delta, int dir) {
    ball.update_pos(delta);
    paddle.update_pos(delta, dir);
    for (auto* col : colliders) {
        CollisionResult collision = collision_system.collide(*col);
        if (!collision.hit) {
            continue;
        }

        if (collision.reset_ball) {
            ball.reset();
            return;
        }

        ball.on_collide(delta, collision);
    }
}

void Game::render(SDL_Renderer* renderer) {
    paddle.render(renderer);
    ball.render(renderer);
}

Game::~Game() {}
