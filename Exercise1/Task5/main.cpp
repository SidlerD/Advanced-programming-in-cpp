#include <stdio.h>
#include <iostream>

using namespace std;

/* 
Task 5: 
    This function is marked inline, but will not be inlined. We can show this by searching for
    "Added" in the assembly code. If the function is actually inlined by the compiler, we would 
    see "Added" in multiple locations.
    This function is not inlined because it has an optional parameter:
    https://learn.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-170$
    Other examples of not-inlineable functions would be recursive functions, as long as 
    pragma inline_recursion(on) is not set.
*/
inline void addToRef(int *ref, int a = 1) {
    *ref += a; cout << "Added " << a << endl;
}

int main(){
    int ref = 5;
    cout << ref << endl;
    addToRef(&ref, 5);
    cout << ref << endl;
    addToRef(&ref);
    cout << ref << endl;

    return 0;
}