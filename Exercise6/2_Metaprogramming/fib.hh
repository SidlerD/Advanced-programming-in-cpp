#pragma once

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
