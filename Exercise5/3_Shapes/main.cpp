#include "Square.h"
#include "Rectangle.h"
#include <iostream>

int main(){
    // Every Square is a rectangle, but not every rectangle is a square
    Rectangle r(2,5);
    Square s(5);

    std::cout << "r.area = " << r.area() << "\n";
    std::cout << "s.area = " << s.area() << "\n";



    return 0;
}