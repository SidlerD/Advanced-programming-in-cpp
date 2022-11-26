#pragma once

#include "player.h"
#include <iostream>
// #include <string>

template <typename F>
struct human_player: public player {
    std::string name;

    int play(const F &field){ //return 1;
        int col;
        std::cout << name << ": Column to play: ";
        std::cin >> col;
        return col;
    };
    human_player(std::string player_name = "Player"): name(player_name) {};
};