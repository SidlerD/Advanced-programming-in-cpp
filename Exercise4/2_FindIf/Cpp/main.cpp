#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

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
    auto start = std::chrono::high_resolution_clock::now();
    auto elemInt = std::find_if(intvec.begin(), intvec.end(), int_lambda);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << *elemInt << " was found in " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()  
        << " ms" << std::endl;
    
    // Benchmark string
    start = std::chrono::high_resolution_clock::now();
    auto elemString = std::find_if(stringvec.begin(), stringvec.end(), string_lambda);
    end = std::chrono::high_resolution_clock::now();
    std::cout << *elemString << " was found in " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()  
        << " ms" << std::endl;
}

int main(){
    benchmark();
    return 0;
}