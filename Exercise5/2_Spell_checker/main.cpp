#include "spell_checker.h"

int main(int argc, char** argv) {
    std::string dict_name = argc>2 ? argv[1] : "dict.txt", 
                file_name = argc>3 ? argv[2] : "text.txt";

    spell_checker checker(dict_name, file_name);

    return 0;
}