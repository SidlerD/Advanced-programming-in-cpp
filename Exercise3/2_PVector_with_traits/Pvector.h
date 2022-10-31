#ifndef PVECTOR_H
#define PVECTOR_H

#include <string>
#include <vector>
#include <fstream>
#include "persist_traits.h"


template <typename T, typename P=persistence_traits<T>>
class pvector{
    std::string filename;
    std::vector<T> v;

    void readvector() {
        std::ifstream ifs(filename);
        T elem;
        while(ifs.good()) {
            persistence_traits<T>::read(ifs, elem);
            v.push_back(elem);
        }
    }

    void writevector(){
        std::ofstream ofs(filename);
        for (const T &elem : v) persistence_traits<T>::write(ofs, elem);
    }
public:
    pvector<T, P>(std::string fname): filename(fname) { readvector(); }

    ~pvector<T, P>() { writevector(); }

    friend std::ostream& operator<<(std::ostream &os, pvector<T, P> &vec){
        auto first = vec.v.begin(); auto last = vec.v.end();
        while(first != last) os << *(first++) << ", ";
        return os << std::endl;
    };

    void push_back(const T &el) { v.push_back(el); }
    void pop_back() { v.pop_back(); }
    T back() { return v.back(); }
};

#endif