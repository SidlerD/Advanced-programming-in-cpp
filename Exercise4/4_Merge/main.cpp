#include "merge-containers.hh"
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <numeric> // iota

auto vec_examples(){
    std::vector<int> vec(20);
    std::iota(vec.begin(), vec.end(), 0);

    std::vector<int> vec2(20);
    std::iota(vec2.begin(), vec2.end(), 50);

    return merge(vec, vec2);
}

auto set_examples(){
    std::set<int> s1({0, 2, 4, 6, 8});
    std::set<int> s2({1, 3, 5, 7, 9});

    return merge(s1, s2);
}

auto map_examples(){
    std::map<std::string, int> m1;
    m1["Max"] = 5; m1["Levin"] = 23; m1["Jarad"] = 999;

    std::map<std::string, int> m2;
    m2["Lena"] = 17; m2["Mirjam"] = 43; m1["Nathalie"] = 734;

    return merge(m1, m2);
}

auto stack_examples(){
    std::stack<std::string> s1; s1.push("hello"); s1.push("world"); s1.pop(); s1.push("la monde");
    std::stack<std::string> s2; s2.push("other"); s2.push("stack");
    return merge(s1, s2);   
}

int main(){
    display_merged(vec_examples());
    display_merged(set_examples());
    display_merged_map(map_examples());
    display_merged(stack_examples());
    return 0;
}