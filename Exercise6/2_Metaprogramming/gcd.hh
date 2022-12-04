#pragma once

template <int A, int B>
struct _gcd{
    static const int res = _gcd<B, A%B>::res;
};

template<int A>
struct _gcd<A, 0>{
    static const int res = A;
};

template <int A, int B>
struct gcd{
    static const int res = _gcd<A, B>::res;
};

int gcdf(int a, int b){
    return (b==0) ? a : gcdf(b, a%b);
}