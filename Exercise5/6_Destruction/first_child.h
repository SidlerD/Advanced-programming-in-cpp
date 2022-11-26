#pragma once
#include <iostream>
#include "base.h"
#include "member1.h"

class first_child: public base{
    member1 m;
public:
    first_child(): m("of first_child") {
        std::cout << "Created first_child\n";
    }
    ~first_child(){
        std::cout << "Destructed first_child\n";
    }
    virtual void foo(){
        std::cout << "first_child.foo()\n"; 
    }
};