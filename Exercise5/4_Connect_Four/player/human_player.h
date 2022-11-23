#pragma once

#include "player.h"
#include "../field/playfield.h"
#include <iostream>
// #include <string>

struct human_player {
    std::string name;

    int play(const playfield &field){ //return 1;
        int col;
        std::cout << name << ": Column to play: ";
        std::cin >> col;
        return col;
    };
    human_player(std::string player_name = "Player"): name(player_name) {};
};