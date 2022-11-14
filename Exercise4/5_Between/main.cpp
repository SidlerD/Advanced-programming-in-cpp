#include <iterator>
#include <vector>
#include <forward_list>
#include <iostream>
#include "between.h"


int main(){
    std::cout << std::boolalpha; // Print true/false instead of 0/1

    std::vector<int> intvec(40);
    std::cout << "begin < (begin + size / 2) < end: " << between(intvec.begin(), intvec.end(), intvec.begin() + intvec.size() / 2) << std::endl;
    std::cout << "begin < (begin - size / 2) < end: " << between(intvec.begin(), intvec.end(), intvec.begin() - intvec.size() / 2) << std::endl;
    std::cout << "begin < begin < end: " << between(intvec.begin(), intvec.end(), intvec.begin()) << std::endl;
    std::cout << "begin < end < end: " << between(intvec.begin(), intvec.end(), intvec.end()) << std::endl;
    std::cout << std::endl;
    
    std::forward_list<int> intlist(20);
    std::cout << "begin < begin + 3 < end: " << between(intlist.begin(), intlist.end(), ++(++(++intlist.begin()))) << std::endl;
    std::cout << "begin < end < begin + 3: "<< between(intlist.begin(), ++++++intlist.begin(), intlist.end()) << std::endl;
    std::cout << "begin < begin < end: "<< between(intlist.begin(), intlist.end(), intlist.begin()) << std::endl;
    std::cout << "begin < end < end: "<< between(intlist.begin(), intlist.end(), intlist.end()) << std::endl;

    return 0;
}