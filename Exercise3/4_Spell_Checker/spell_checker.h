#pragma once

#include <iostream>
#include <fstream>
#include "pset.h"
#include <vector>

struct persistence_traits_for_words {
    static void read(std::ifstream &i, std::string &elem) {
        i >> elem;
    }
    static void write(std::ofstream &o, const std::string &elem) {
        o << elem << std::endl;
    } 
};


class spell_checker{
    std::string dict_loc, text_loc;
    pset<std::string, persistence_traits_for_words> dict;

    // std::set<std::string> extract_dict(){
    //     std::ifstream dict_stream(dict_loc);
    //     std::string word;
    //     std::set<std::string> set;
    //     while(dict_stream.good()){
    //         dict_stream >> word;
    //         set.insert(word);
    //     }
    //     return set;
    // }

    void check_words(){
        std::ifstream ifs(text_loc);
        std::vector<std::string> wrong_words;
        std::string word; char add;

        while(ifs >> word){
            if(dict.count(word) == 0) { // word not in dict
                std::cout << '"' << word << '"' << " is not in the dictionary. Do you want to add it? [y/n] ";
                std::cin >> add; 
                if(add == 'y') dict.insert(word);
                else wrong_words.push_back(word);
            }
        }

    }

public:
    spell_checker(std::string dictl, std::string textl): dict_loc(dictl), text_loc(textl), dict(dictl) {
        // extract_dict();
        check_words();
    }
};  
