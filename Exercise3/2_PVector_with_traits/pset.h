#ifndef PSET_H
#define PSET_H

#include <string>
#include <set>
#include <vector>
#include <fstream>
#include "persist_traits.h"


template <typename T, typename P=persistence_traits<T>>
class pset{
    std::string filename;
    std::set<T> set;

    void readset() {
        std::ifstream ifs(filename);
        T elem;
        while(ifs.good()) {
            persistence_traits<T>::read(ifs, elem);
            set.insert(elem);
        }
        std::cout << "Set after constructing: " << *this << std::endl;
    }

    void writeset(){
        std::ofstream ofs(filename);
        for (const T &elem : set) persistence_traits<T>::write(ofs, elem);
    }
public:
    pset<T, P>(std::string fname): filename(fname) { readset(); }

    ~pset<T, P>() { writeset(); }

    friend std::ostream& operator<<(std::ostream &os, pset<T, P> &ps){
        for (auto it = ps.set.cbegin(); it != ps.set.cend(); it++) {
            std::cout << *it << ", ";
        }    
        return os << std::endl;
    };

    void insert(const T &el) { set.insert(el); }
    T back() { return set.back(); }
};

#endif