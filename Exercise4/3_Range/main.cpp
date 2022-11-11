#include <iostream>
#include "range.h"

int main(){
    // range r(10,20);

    // for(auto i : r) std::cout << i << std::endl;
    // auto first = r.begin(), last = r.end();
    // for(;first < last; ++first){
    //     std::cout << *first << std::endl;
    // }

    for(auto i : range(10,20)) std::cout << i << std::endl;
    return 0;
}