#include "fib.hh"
#include "gcd.hh"
#include <vector>
#include <iostream>


int main(){
    std::vector<int> vec(fib<9>::res);
    std::cout << vec.size() << std::endl;

    std::vector<int> vec2(gcd<256, 28>::res);
    std::cout << vec2.size() << std::endl;
    
    // Why do we need metaprogramming instead of just functions?
    std::vector<int> vec3(gcdf(256, 28));
    std::cout << vec3.size() << std::endl;
    
    return 0;
}