// #include "../Task2_1/Pvector.h"
#include "fraction.h"
#include <iostream>
#include <complex>
#include "rpn.h"

int main(){
    rpn<std::complex<double>> compl_rpn("./persist/compl.txt");
    compl_rpn.run();

    return 0;
}