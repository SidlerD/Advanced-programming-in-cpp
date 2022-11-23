#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include "../field/playfield.h"
class player {
public:
    virtual int play(const playfield &field) = 0;
    virtual ~player() {}
};
#endif /* PLAYER_H_ */