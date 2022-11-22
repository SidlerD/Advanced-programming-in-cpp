#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using std::string;
using std::vector;
using std::ifstream;
using std::regex_match;


class spell_checker{
    string dict_loc, text_loc;
    vector<std::regex> dict;

    void check_words(){
        ifstream ifs(text_loc);
        std::stringstream buffer; buffer << ifs.rdbuf();
        string s = buffer.str();

        std::regex r_words(R"(\w+)");
        auto words_begin = std::sregex_iterator(s.begin(), s.end(), r_words),
            words_end = std::sregex_iterator();

        for(;words_begin != words_end; ++words_begin){
            std::smatch word_match = *words_begin;
            string word = word_match.str();

            bool match = false;
            for(auto const& reg: dict){
                if(regex_match(word, reg)) { match = true; break;}
            }
            if(!match){
                std::cout << '"' << word << '"' << " is not in the dictionary" << "\n"; 
            }
        }

    }

    void extract_dict(){
        ifstream ifs(dict_loc);
        string word;
        while(ifs.good()){
            ifs >> word;
            dict.push_back(std::regex(word));
        }
    }

public:
    spell_checker(string dictl, string textl): 
        dict_loc(dictl), 
        text_loc(textl)
    { 
        extract_dict();
        check_words(); 
    }
};  
