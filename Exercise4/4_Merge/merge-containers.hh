#pragma once

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>
#include <stack>

// https://devblogs.microsoft.com/oldnewthing/20190619-00/?p=102599
template<typename C, typename T = typename C::value_type>
C merge(const C& cont1, const C& cont2){
    C m(cont1); // Copy contents of container 1

    std::copy(cont2.begin(), cont2.end(), std::inserter(m, m.end())); // Copy contents of container 2
    
    return m;
}

template <typename T>
std::stack<T> merge(const std::stack<T>& cont1, const std::stack<T>& cont2){
    std::stack<T> m(cont1); // Copy contents of container 1
    std::stack<T> m2(cont2); // Copy container 1

    std::vector<T> vec; // helper
    
    while(!m2.empty()){
        vec.push_back(m2.top());
        m2.pop();
    }
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        m.push(*it);
    }
    return m;
}


template <typename T>
void display_merged(T container){
    std::copy(container.begin(), container.end(),
        std::ostream_iterator<typename T::value_type>(std::cout, " "));
    
    std::cout << std::endl;
}

template <typename T>
void display_merged(std::stack<T> container){
    std::stack<T> s(container);
    std::vector<T> vec; // helper
    
    while(!s.empty()){
        vec.push_back(s.top());
        s.pop();
    }
    
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
}


template<typename K, typename V>
void display_merged(std::map<K, V> map){
    for(const auto& elem: map){
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
}