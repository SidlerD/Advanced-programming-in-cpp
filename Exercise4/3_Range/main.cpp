#include <iostream>
#include "range.h"

int main(){
    // range r(10,20);

    // for(auto i : r) std::cout << i << std::endl;
    // auto first = r.begin(), last = r.end();
    // for(;first < last; ++first){
    //     std::cout << *first << std::endl;
    // }
    try {
        for(auto i : range(10,20)) std::cout << i << std::endl;
    }
    catch(const std::exception& e){}
    
    try {
        for(auto i: range(12, 12)) std::cout << i << std::endl;
    }
    catch(const std::exception& e){}
    
    try {
        for(auto i: range(12, 11)) std::cout << i << std::endl;
    }
    catch(const std::exception& e){}


    return 0;
}