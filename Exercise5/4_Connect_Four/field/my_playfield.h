#pragma once
#include <stdexcept>
#include <iostream>
#include "playfield.h"

struct my_playfield: playfield {
    const static int width=7;
    const static int height=6;

    // these elements are used to indicate whether a given position
    // in the playing field is taken by a given player
    const static char none=0;
    const static char player1=1;
    const static char player2=2;

    // the internal representation of the field
    char rep[playfield::width][playfield::height]; // TODO: Why not switch height and width here?

    int stoneat(int x, int y) const { return rep[x][y]; }

    my_playfield() : rep() {};
};