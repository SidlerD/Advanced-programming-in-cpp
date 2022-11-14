#pragma once

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

// https://devblogs.microsoft.com/oldnewthing/20190619-00/?p=102599
template<typename C, typename T = typename C::value_type>
std::vector<T> merge(const C& cont1, const C& cont2){
    std::vector<T> vec; vec.reserve(cont1.size() + cont2.size());

    std::copy(cont1.begin(), cont1.end(), std::back_inserter(vec));
    std::copy(cont2.begin(), cont2.end(), std::back_inserter(vec));
    
    // Display 
    std::copy(vec.begin(), vec.end(),
        std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
    return vec;
}