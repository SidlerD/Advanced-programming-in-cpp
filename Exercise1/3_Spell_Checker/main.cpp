#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

set<string> extract_dict(ifstream &ifs){
    set<string> dict = set<string>();
    string word;
    while(ifs.good()){
        ifs >> word;
        dict.insert(word);
    }
    return dict;
}

vector<string> check_words(ifstream &ifs, const set<string> dict){
    vector<string> wrong_words = vector<string>();
    string word;
    while(ifs >> word){
        if(dict.count(word) == 0) {
            wrong_words.push_back(word);
            cout << word << " " << endl;
        }
    }
    return wrong_words;
}


int main(int argc, char** argv) {
    if(argc < 3) return -1;

    string dict_name = argv[1], file_name = argv[2];
    ifstream dict_stream = ifstream(dict_name);
    ifstream text_stream = ifstream(file_name);

    set<string> dict = extract_dict(dict_stream);

    check_words(text_stream, dict);
    return 0;
}