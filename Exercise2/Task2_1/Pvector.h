#ifndef PVECTOR_H
#define PVECTOR_H

#include <string>
#include <vector>

template<typename T>
class Pvector {
    std::string filename;
    std::vector<T> v;
    void readvector();
    void writevector();
public:
    Pvector<T>(std::string fname);
    ~Pvector<T>();
    void push_back(const T &el);
    void pop_back();

    void clear(){v.clear();}
    int size(){return v.size();}
    T back();

};
#endif