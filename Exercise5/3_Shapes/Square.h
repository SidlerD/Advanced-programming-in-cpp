#pragma once
#include "Rectangle.h"

class Square: public Rectangle {
public:
    Square(double length): Rectangle(length, length){}
};