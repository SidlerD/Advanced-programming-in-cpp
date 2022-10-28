#include "pvector.h"
#include <string>
#include <fstream>

using namespace std;

template<class T>
void Pvector<T>::readvector() {
    ifstream ifs(Pvector<T>::filename);
    for(;;) {
        T x; ifs >> x; if(!ifs.good()) break;
        Pvector<T>::v.push_back(x);
    }
}

template<class T>
void Pvector<T>::writevector(){
    ofstream ofs(Pvector<T>::filename);
    for (const T &elem : Pvector<T>::v) ofs << elem << endl;
}

template<class T>
Pvector<T>::Pvector(string fname): filename(fname) { readvector(); }

template<class T>
Pvector<T>::~Pvector() { writevector(); }

template<class T>
void Pvector<T>::push_back(const T &el) { Pvector<T>::v.push_back(el); }
template<class T>
void Pvector<T>::pop_back() { Pvector<T>::v.pop_back(); }
template<class T>
T Pvector<T>::back() { return v.back(); }