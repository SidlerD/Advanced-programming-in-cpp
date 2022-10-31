#include <string>
#include <iostream>
#include "Pvector.h"

using namespace std;

/* Problems:
 * String: If user pushes string with spaces, destroys pvec and opens it again,
           every word in that original string ends up as individual string
 * double: Number gets rounded when writing to file
           https://stackoverflow.com/questions/18130511/unexpected-rounding-of-double-types-in-c-writing-to-file

 * int: Values with leading 0's lead to weird values written to file
        But this seems to be a something else, not a problem with my class
 */

int main(int argc, char**argv){
    string fname = (argc > 1) ? argv[1] : "pvector.txt";
    Pvector<string> vec(fname);
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

    return 0;
}