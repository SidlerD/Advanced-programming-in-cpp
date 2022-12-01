#pragma once
#include "Shape.h"

class Rectangle: public Shape {
protected:
    double a, b;
public:
    Rectangle(double width, double height): a(width), b(height){}
    virtual double area(){ return a * b; }
    virtual double circumference(){ return 2*a + 2*b; }
    virtual double get_height(){ return b; }
    virtual double get_width(){ return a; }
};