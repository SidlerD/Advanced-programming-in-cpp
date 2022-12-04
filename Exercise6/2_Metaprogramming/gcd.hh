#pragma once

template <int A, int B>
struct gcd{
    static const int res = gcd<B, A%B>::res;
};
template<int A>
struct gcd<A, 0>{
    static const int res = A;
};

int gcdf(int a, int b){
    return (b==0) ? a : gcdf(b, a%b);
}