#pragma once

template <unsigned int N>
struct fib_impl{
    static const int res = fib_impl<N-1>::res + fib_impl<N-2>::res;
};

template <>
struct fib_impl<1>{
    static const int res = 1;
};
template <>
struct fib_impl<0>{
    static const int res = 0;
};

template <unsigned int N>
struct fib{
    static const int res = fib_impl<N>::res;
};