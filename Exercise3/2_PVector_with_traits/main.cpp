#include <string>
#include <iostream>
#include "pvector.h"
#include "pset.h"

void pvec_examples(std::string fname){
    std::cout << "<<<<<<<<< pvector >>>>>>>>>" << std::endl;
    pvector<std::string> vec(fname);
    vec.push_back("Hello world this is all in one string");
    vec.push_back("This is a new string");

    std::cout << vec;
    // Pvector<double> double_vec(fname);
    // double_vec.push_back(3.141596);
    // double_vec.push_back(-1.234567890);
    // double_vec.push_back(0);
    
    // Pvector<int> int_vec(fname);   
    // int_vec.push_back(-1234567890);
    // int_vec.push_back(1000000000);
    // int_vec.push_back(123);
    // int_vec.push_back(-1010101010);

    // std::cout << int_vec;
    std::cout << "-------------------------" << std::endl;
}

void pset_examples(std::string fname){
    std::cout << "<<<<<<<<< pset >>>>>>>>>" << std::endl;
    pset<std::string> set(fname);
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if(input == "q") break;
        set.insert(input);
    }
    

    std::cout << set;
    std::cout << "-------------------------" << std::endl;
}


int main(int argc, char**argv){
    std::string vec_fname = (argc > 1) ? argv[1] : "pvector.txt";
    std::string set_fname = (argc > 2) ? argv[2] : "pset.txt";
    // pvec_examples(vec_fname);
    pset_examples(set_fname);

    return 0;
}