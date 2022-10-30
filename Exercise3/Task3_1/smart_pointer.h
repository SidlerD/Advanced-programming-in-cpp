#pragma once
#include <iostream>

template <typename T>
class smart_pointer{
    T* pointer;
    int* cnt;
    int i = 1;
    
public:
    smart_pointer<T>(T *el): pointer(el) { cnt = &i; }; 
    smart_pointer<T>(const smart_pointer<T>& other): pointer(other.pointer) { 
        // std::cout << /*", *(other.cnt): " << */*(other.cnt);
        cnt = other.cnt;
        (*cnt)++; 
    } // Copy-constructor
    ~smart_pointer<T>(){
        --(*cnt);
        if(*cnt == 0) delete pointer;
    }

    T operator*(){ return *pointer; } 
    // T* operator->() { return pointer; }

    smart_pointer<T>& operator=(const smart_pointer<T> &pnt){
        --(*cnt); // Decrease count of old T
        cnt = pnt.cnt; pointer = pnt.pointer;
        ++cnt; // Increase count of new T
        return *this; // For chaining I think
    }

    int counter(){ 
        int c = *cnt;
        return c; 
    }
};