#include "merge-containers.hh"
#include <vector>
#include <set>
#include <numeric> // iota

void vec_examples(){
    std::vector<int> vec(20);
    std::iota(vec.begin(), vec.end(), 0);

    std::vector<int> vec2(20);
    std::iota(vec2.begin(), vec2.end(), 50);

    std::vector<int> merged = merge(vec, vec2);
}

void set_examples(){
    std::set<int> s1({0, 2, 4, 6, 8});
    std::set<int> s2({1, 3, 5, 7, 9});

    std::vector<int> merged = merge(s1, s2);
}


int main(){
    vec_examples();
    set_examples();

    return 0;
}