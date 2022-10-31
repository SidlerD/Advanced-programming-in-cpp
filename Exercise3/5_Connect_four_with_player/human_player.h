#pragma once

#include "player.h"
#include <iostream>
// #include <string>

template <typename F>
struct human_player {
    std::string name;

    int play(const F &field){ //return 1;
        int row;
        std::cout << name << ":\tRow to play: ";
        std::cin >> row;
        return row;
    };
    human_player(std::string player_name = "player"): name(player_name) {};
};