#include "game.hpp"
#include <iostream>
#include <functional>

Game::Game(const GameConfig& cfg):
    paddle(cfg.paddle,
           (cfg.window.width - cfg.paddle.width) / 2,
           cfg.window.height - cfg.paddle.height - cfg.paddle.bottom_offset,
           cfg.window.width),
    ball(cfg.ball,
         (cfg.window.width - cfg.ball.width) / 2,
         (cfg.window.height - cfg.ball.height) / 2),

    // Init walls
    top_wall({0, 0, cfg.window.width, cfg.wall.thickness, false, false, true}),
    buttom_wall({0, cfg.window.height - cfg.wall.thickness,
                 cfg.window.width, cfg.wall.thickness, true, false, false}),
    left_wall({0, 0, cfg.wall.thickness, cfg.window.height, false, true, false}),
    rigth_wall({cfg.window.width - cfg.wall.thickness, 0,
                cfg.wall.thickness, cfg.window.height, false, true, false}),

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
