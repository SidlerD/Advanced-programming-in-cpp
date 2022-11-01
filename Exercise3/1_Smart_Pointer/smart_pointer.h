#pragma once
#include <iostream>

template <typename T>
class smart_pointer{
    T* pointer;
    int* cnt;
    
public:
    smart_pointer<T>(T *el): pointer(el) { cnt = (int*) malloc(sizeof(int)); *cnt = 1; };  // malloc because otherwise the pointer address becomes invalid after constructor is closed
    smart_pointer<T>(const smart_pointer<T>& other): pointer(other.pointer) { 
        cnt = other.cnt;
        (*cnt)++; 
    } // Copy-constructor
    ~smart_pointer<T>(){
        --(*cnt);
        if(*cnt == 0) {
            delete pointer;
            free(cnt);
        }
    }

    T operator*(){ return *pointer; } 
    T* operator->() { return pointer; }

    smart_pointer<T>& operator=(const smart_pointer<T> &other){
        --(*cnt); // Decrease count of old T since we don't point to that anymore
        cnt = other.cnt; pointer = other.pointer;
        ++(*cnt); // Increase count of new T
        return *this; // For chaining I think
    }

    int counter(){ 
        int c = *cnt;
        return c; 
    }
};