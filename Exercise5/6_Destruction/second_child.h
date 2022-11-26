#pragma once
#include <iostream>
#include "first_child.h"
#include "member2.h"

class second_child: public first_child{
    member2 m;
public:
    second_child(): m("of second_child") {
        std::cout << "Created second_child\n";
    }
    ~second_child(){
        std::cout << "Destructed second_child\n";
    }
    virtual void foo(){
        std::cout << "second_child.foo()\n"; 
    }
};