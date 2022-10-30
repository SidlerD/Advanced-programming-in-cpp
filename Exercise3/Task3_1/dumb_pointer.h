#pragma once
#include <iostream>

template <typename T>
class dumb_pointer{
    T* pointer;
public:
    dumb_pointer<T>(T &el): pointer(&el) { }; // T& instead of only T is very important here!!!
    T operator*(){ return *pointer; } // Not sure if this does the right thing, see (*vecp).push_back(3)
    T* operator->() { return pointer; }
};