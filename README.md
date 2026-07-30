# Pong

A lightweight C++ implementation of the classic Pong game using SDL2 and SDL2_ttf.

## Features

- 2D paddle and ball physics
- Block and wall collision handling
- Simple game loop using SDL2
- Text rendering with SDL2_ttf

## Project Structure

- `src/` - C++ source files
  - `main.cpp` - application entry point
  - `game/` - game object implementations (ball, block, paddle, wall, game logic)
  - `game/collision/` - collision system utilities
- `assets/config/game.json` - game configuration data
- `CMakeLists.txt` - build configuration

## Build Instructions

### Prerequisites

- C++17 compatible compiler
- CMake 3.20+
- SDL2 development libraries
- SDL2_ttf development libraries

### Build

```bash
mkdir -p build
cd build
cmake ..
make
```

### Run

```bash
./pong/pong
```

## Notes

This repository is a simple Pong clone intended for learning C++ game development with SDL2.