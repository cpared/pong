#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "game/game.hpp"
#include "config/game_config.hpp"

const int ERR = 1;
const int OK = 0;

GameConfig load_game_config(const std::string& path) {
    std::ifstream in(path);
    nlohmann::json j;
    in >> j;

    int window_width = j.at("window").at("width").get<int>();
    int window_height = j.at("window").at("height").get<int>();
    std::string window_title = j.at("window").at("title").get<std::string>();
    int window_FPS = j.at("window").at("target_fps").get<int>();

    WindowConfig windowCfg = {
        window_width,
        window_height,
        window_title,
        window_FPS,
    };

    int ball_width = j.at("ball").at("width").get<int>();
    int ball_height = j.at("ball").at("height").get<int>();
    float ball_speed = j.at("ball").at("speed").get<float>();

    BallConfig ballCfg = {
        ball_width,
        ball_height,
        ball_speed,
    };

    int paddle_width = j.at("paddle").at("width").get<int>();
    int paddle_height = j.at("paddle").at("height").get<int>();
    float paddle_speed = j.at("paddle").at("speed").get<float>();
    int paddle_bottom_offset = j.at("paddle").at("bottom_offset").get<int>();

    PaddleConfig paddleCfg = {
        paddle_width,
        paddle_height,
        paddle_speed,
        paddle_bottom_offset,
    };

    WallConfig wallCfg = {
        j.at("wall").at("thickness").get<int>(),
    };

    return GameConfig{
        windowCfg,
        ballCfg,
        paddleCfg,
        wallCfg,
    };
}

int main(int args, char *argn[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "cannot initialize SDL - ERR: " << SDL_GetError() << std::endl;
        return ERR;
    }

    const GameConfig config = load_game_config("assets/config/game.json");

    SDL_Window* window = SDL_CreateWindow(
        config.window.title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config.window.width,
        config.window.height, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Uint64 frameStart;
    int delta = 10;
    SDL_Event event;

    Game game(config);
    int dir = 0;

    // EVENT LOOP
    bool _running = true;
    float MIN_FRAME_TIME = 1000 / config.window.FPS;
    while (_running) {
        frameStart = SDL_GetTicks64();

        // procces_events()
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                _running = false;
                break;
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_LEFT) {
                    dir = -1;
                }

                if (event.key.keysym.sym == SDLK_RIGHT) {
                    dir = 1;
                }
            }

            if (event.type == SDL_KEYUP) {
                dir = 0;
            }
        }

        game.run(MIN_FRAME_TIME, dir);

        // render()
        // SET BACKGROUND COLOR
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // CLEAN PREVIOUS WINDOW
        SDL_RenderClear(renderer);

        // SET RENDERER NEW VALUES
        game.render(renderer);

        // DRAW
        SDL_RenderPresent(renderer);

        // delay()
        delta = SDL_GetTicks64() - frameStart;
        if (delta < MIN_FRAME_TIME)
            SDL_Delay(MIN_FRAME_TIME);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return OK;
}
