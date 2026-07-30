#ifndef SRC_CONFIG_GAME_CONFIG_HPP_
#define SRC_CONFIG_GAME_CONFIG_HPP_

#include <string>

struct WindowConfig {
    int width;
    int height;
    std::string title;
    int FPS;
};

struct BallConfig {
    int width;
    int height;
    float speed;
};

struct PaddleConfig {
    int width;
    int height;
    float speed;
};

struct GameConfig {
    WindowConfig window;
    BallConfig ball;
    PaddleConfig paddle;
};


#endif  // SRC_CONFIG_GAME_CONFIG_HPP_
