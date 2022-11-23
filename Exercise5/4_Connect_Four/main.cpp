#include <iostream>
#include "game/connect_four.h"
#include "player/human_player.h"
#include "player/dominik.h"
#include "field/my_playfield.h"

int main(){
    connect_four<dominik, human_player, my_playfield> game;
    game.run();
    return 0;
} 