#include "Square.h"
#include "Rectangle.h"
#include <iostream>
#include <vector>

std::vector<double> calc_middle(Rectangle rect){
    return std::vector<double> ({rect.get_width()/2, rect.get_height()/2});
}

int main(){
    // Every Square is a rectangle, but not every rectangle is a square
    
    Rectangle r(2,5); // Not semantically equivalent to any Square
    Square s(5); // Semantically equal to Rectangle(5,5)

    // Problem: Rectangle could expose a method like setWidth & setHeight, which Square can't support
    // But if Square was parent of Rect, then Rect would be limited in it's functionality
    std::cout << "r.area = " << r.area() << "\n";
    std::cout << "s.area = " << s.area() << "\n";

    auto rmid = calc_middle(r);
    auto smid = calc_middle(s);
    std::cout << "Middle of r = " << rmid[0] << ", " << rmid[1] << std::endl;
    std::cout << "Middle of s = " << smid[0] << ", " << smid[1] << std::endl;


    return 0;
}