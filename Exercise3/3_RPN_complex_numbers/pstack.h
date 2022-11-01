#pragma once
#include "pvector.h"

template <typename T>
struct min_trait{
    static T min(T a, T b){return std::min(a, b); }
};

template<typename P>
struct min_trait<std::complex<P>>{
    static std::complex<P> min(std::complex<P> a, std::complex<P> b){
        return (abs(a) < abs(b)) ? a : b;
    }
};

template <typename T, typename M = min_trait<T>>
class pstack{
    pvector<T> vec;
public:
    pstack(std::string fname):
        vec(fname)
    {/* void */};
    pstack(const pstack&) = delete; // Copy constructor

    void push(T val){
        vec.push_back(val);
    }

    T pop(){
        if(vec.size() == 0) throw("No elements left on the stack");
        T val = vec.back();
        vec.pop_back();
        return val;
    }

    T min(){
        int s = vec.size();
        if(s < 2) throw "Not enough elements left on stack!";
        T a = vec.at(s-1), b = vec.at(s-2);
        return M::min(a, b);
    }

    friend std::ostream& operator<<(std::ostream &os, pstack &stack){
        if(stack.size() == 0) return os;
        int i = 0;
        for(auto it = stack.vec.begin(); it != stack.vec.end(); it++){
            os << i++ << ": " << *it << std::endl;
        }
        return os;
    }

    int size(){ return vec.size();}
    void clear(){ vec.clear();}
    T at(int n){ return vec.at(n); }
};