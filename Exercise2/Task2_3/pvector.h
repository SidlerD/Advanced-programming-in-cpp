#ifndef PVECTOR_H
#define PVECTOR_H

#include <string>
#include <vector>

template<typename T>
class pvector {
    std::string filename;
    std::vector<T> v;
    void readvector();
    void writevector();
public:
    pvector<T>(std::string fname);
    ~pvector<T>()/*{writevector();}*/;
    void push_back(const T &el);
    void pop_back();
    typename std::vector<T>::const_iterator begin(){ return v.begin(); };
    typename std::vector<T>::const_iterator end(){ return v.end(); };

    void clear(){v.clear();}
    int size(){return v.size();}
    T back();

    // std::ostream& operator<<(ostream &os, pvector<T> &vec);

};
#endif