#pragma once
#include <iostream>
#include <string>

class member1{
    std::string n;
public:
    member1(std::string name): n(name){
        std::cout << "Created member1 " << n << std::endl;
    }
    ~member1(){
        std::cout << "Destructed member1 " << n << std::endl;
    }
};