cmake_minimum_required(VERSION 3.20)

project(pong VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)
pkg_check_modules(SDL2_TTF REQUIRED IMPORTED_TARGET SDL2_ttf)

add_executable(pong
    src/main.cpp
    src/game/ball.cpp
    src/game/block.cpp
    src/game/game.cpp
    src/game/paddle.cpp
    src/game/wall.cpp
    src/game/collision/collision_system.cpp
)

target_include_directories(pong PRIVATE src)
target_link_libraries(pong PRIVATE PkgConfig::SDL2 PkgConfig::SDL2_TTF)

target_compile_options(pong PRIVATE -Wall -Wextra -Wpedantic)
