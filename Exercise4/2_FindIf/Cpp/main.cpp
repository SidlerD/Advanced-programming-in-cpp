#include <vector>
#include <iostream>
#include <algorithm>

void benchmark(){
    // Setup
    int n = 10000000;
    std::vector<int> intvec(n, 999);
    intvec.at(n-2) = 111;
    auto int_lambda = [](int i) {return i == 111;};

    std::vector<std::string> stringvec(n, "hello");
    stringvec.at(n-2) = "world";
    auto string_lambda = [](std::string s) {return s == "world";};

    // Benchmark int
    auto elemInt = std::find_if(intvec.begin(), intvec.end(), int_lambda);
    std::cout << *elemInt << std::endl;
    // Benchmark string
    auto elemString = std::find_if(stringvec.begin(), stringvec.end(), string_lambda);
    std::cout << *elemString << std::endl;
}

int main(){
    benchmark();
    return 0;
}