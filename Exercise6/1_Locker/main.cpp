#include "FileLocker.h"
#include <iostream>
#include "pvector.h"

void lockSomeFile(std::string fname){
    FileLocker f(fname);
    std::cout << "-- Doing something with " << fname << " --\n";
}

int main(){
    lockSomeFile("file.txt");

    pvector<int> pvec("vec.txt");
    pvec.push_back(5);pvec.push_back(35);pvec.push_back(42);

    std::cout << "-- End of main --\n";
    return 0;
}

/**
 * Advantages of FIleLocker:
 *  - Easier to (re)use
 *  - Separate responsibilities in separate files/classes
*/