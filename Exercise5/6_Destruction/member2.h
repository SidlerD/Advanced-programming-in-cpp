#pragma once
#include <iostream>
#include <string>

class member2{
    std::string n;
public:
    member2(std::string name): n(name){
        std::cout << "Created member2 " << n << std::endl;
    }
    ~member2(){
        std::cout << "Destructed member2 " << n << std::endl;
    }
};