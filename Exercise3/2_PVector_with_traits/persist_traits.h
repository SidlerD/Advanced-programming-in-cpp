#pragma once 
#include <fstream>


template<typename T>
struct persistence_traits {
    static void read(std::ifstream &i, T &elem) {
        i >> elem;
    }
    static void write(std::ofstream &o, const T &elem) {
        o << elem << std::endl;
    } 
};

template<>
struct persistence_traits<std::string> {
    static void read(std::ifstream &i, std::string &elem) {
        std::getline(i, elem, '\0');
    }
    static void write(std::ofstream &o, const std::string &elem) {
        if(elem != " " && elem != "\0") o << elem << '\0';
    } 
};