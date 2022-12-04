#include "fib.hh"
#include "gcd.hh"
#include <vector>
#include <iostream>


int main(){
    std::vector<int> vec(fib<9>::res);
    std::cout << vec.size() << std::endl;

    std::vector<int> vec2(gcd<256, 28>::res);
    std::cout << vec2.size() << std::endl;
    
    // Why do we need metaprogramming instead of just functions? // nvm, see switch statement
    std::vector<int> vec3(nonconst_gcdf(256, 28));
    std::cout << vec3.size() << std::endl;

    std::cout << fib_fun(0) << ", "<< fib_fun(1) << ", "<< fib_fun(2)  << std::endl;
    std::cout << fib_fun(9) << ", "<< fib_fun(10) << ", "<< fib_fun(11)  << std::endl;
    
    switch (42)
    {
    case fib<9>::res :
        break;
    case fib_fun(45) :
        break;
    case gcd<256, 28>::res :
        break;  
    case gcdf(234, 34):
        break;
    // case nonconst_gcdf(234, 34):
    //     break;
    default:
        break;
    }
    
    return 0;
}