#include "pvector.h"
#include "fraction.h"
#include <string>
#include <fstream>

using namespace std;

template<class T>
void pvector<T>::readvector() {
    ifstream ifs(pvector<T>::filename);
    for(;;) {
        T x; ifs >> x; if(!ifs.good()) break;
        pvector<T>::v.push_back(x);
    }
}

template<class T>
void pvector<T>::writevector(){
    ofstream ofs(pvector<T>::filename);
    for (const T &elem : pvector<T>::v) ofs << elem << endl;
}

template<class T>
pvector<T>::pvector(string fname): filename(fname) { readvector(); }

template<class T>
pvector<T>::~pvector() { writevector(); }

template<class T>
void pvector<T>::push_back(const T &el) { pvector<T>::v.push_back(el); }
template<class T>
void pvector<T>::pop_back() { pvector<T>::v.pop_back(); }
template<class T>
T pvector<T>::back() { return v.back(); }

// template<class T>
// ostream& pvector<T>::operator<<(ostream &os, pvector<T> &vec){
//     if(vec.size() == 0) return os;
//     int i = 0;
//     for(T val: vec){
//         os << i++ << ": " << val << endl;
//     }
//     return os;
// }
// Instantiations
template class pvector<int>;
template class pvector<double>;
template class pvector<fraction>;