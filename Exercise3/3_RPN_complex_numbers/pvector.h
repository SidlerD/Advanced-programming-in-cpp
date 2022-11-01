#ifndef PVECTOR_H
#define PVECTOR_H

#include "pvector.h"
#include "fraction.h"
#include <vector>
#include <string>
#include <fstream>


template<class T>
class pvector{
    std::string filename;
    std::vector<T> v;

    void readvector() {
        std::ifstream ifs(filename);
        for(;;) {
            T x; ifs >> x; if(!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writevector(){
        std::ofstream ofs(filename);
        for (const T &elem : v) ofs << elem << std::endl;
    }
public:
    pvector(std::string fname): filename(fname) { readvector(); }

    ~pvector() { writevector(); }

    void push_back(const T &el) { v.push_back(el); }
    void pop_back() { v.pop_back(); }
    T back() { return v.back(); }
    int size(){ return v.size(); }
    auto begin(){ return v.begin(); }
    auto end(){ return v.end(); }
    T at(int n) { return v.at(n);}
    // ostream& operator<<(ostream &os, pvector<T> &vec){
    //     if(vec.size() == 0) return os;
    //     int i = 0;
    //     for(T val: vec){
    //         os << i++ << ": " << val << endl;
    //     }
    //     return os;
    // }
};

#endif