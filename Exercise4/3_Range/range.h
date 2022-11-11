#pragma once

#include <vector>
#include <stdexcept>
#include <numeric>

class range{
    int s, e, curr;
    // TODO: Check if there's a better way of doing this: For large ranges, this will take up a lot of space
    // Watch the podcast for this bc I think he mentioned it when presenting the exercises
    std::vector<int> vec;

public:
    typedef typename std::vector<int>::iterator iterator;
    range(int start, int end): s(start), e(end), curr(s), vec(e-s){
        if(s >= e){
            throw std::invalid_argument("Start is greater than end for range!");
        }
        std::iota(vec.begin(), vec.end(), s);
    }

    iterator begin(){ return vec.begin();};    
    iterator end(){ return vec.end();};

};