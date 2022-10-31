#include "pvector.cpp"
#include <string>
#include <iostream>
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
    // Pvector<string> vec(fname);
    // vec.push_back("hello world, this is all in one string");

    // Pvector<double> double_vec(fname);
    // double_vec.push_back(3.141596);
    // double_vec.push_back(-1.234567890);
    // double_vec.push_back(0);
    
    Pvector<int> int_vec(fname);
    // int_vec.push_back(-1234567890);
    // int_vec.push_back(1000000000);
    // int_vec.push_back(123);
    int_vec.push_back(0012);
    int_vec.push_back(007001);
    int_vec.push_back(000000005);
    cout << 007001;

    return 0;
}