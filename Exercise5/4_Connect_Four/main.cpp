#include <iostream>
#include "game/connect_four.h"
#include "player/human_player.h"
#include "player/my_player.h"
#include "field/my_playfield.h"

int main(){
    connect_four<my_player, my_player> game;
    // game.test();
    game.run();
    return 0;
} 