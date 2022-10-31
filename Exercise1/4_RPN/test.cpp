#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print_stack(vector<double> stack){
    int size = stack.size();
    auto it = stack.begin();
    for(int i=1; i<=size; i++){
        cout << i << ": " << *it << endl;
        it++;
    }
}



int main(){
    vector<double> stack = {1,2,3,4,5,6,7,8,9};

    // cout << *(stack.end()-1);
    print_stack(stack);
    *(stack.end()-1) = 1;
    // cout << *(stack.end()-1);
    print_stack(stack);

    *(stack.end()) = -1;
    stack.end()++;
    print_stack(stack);

    return 0;
}