#include <iostream>
#include "connect_four.h"
#include "human_player.h"
#include "dominik.h"
#include "playfield.h"

int main(){
    connect_four<human_player<playfield>, human_player<playfield>, playfield> game;
    game.run();
    return 0;
}