#ifndef SRC_GAME_COLLISION_DIRECTIONS_CHANGER_HPP_
#define SRC_GAME_COLLISION_DIRECTIONS_CHANGER_HPP_

#include <array>

class DirectionsChanger {
    public:
        ~DirectionsChanger() = default;
        virtual std::array<bool, 2> should_change_directions() const = 0;

    private:
};

#endif  // SRC_GAME_COLLISION_DIRECTIONS_CHANGER_HPP_
