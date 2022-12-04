#pragma once
#include <algorithm>

template <unsigned int N>
struct fib{
    static const int res = fib<N-1>::res + fib<N-2>::res;
};

template <>
struct fib<1>{
    static const int res = 1;
};
template <>
struct fib<0>{
    static const int res = 0;
};

// With constexpr
constexpr int fib_fun(int n){
    int a=0, b=1;
    for(int i=0; i<n; ++i){
        if(i%2) a += b;
        else b += a;
    }
    return (n-1)%2 ? a : b;
}