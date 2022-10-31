// #include "../Task2_1/Pvector.h"
#include "pvector.h"
#include "fraction.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

template <typename T>
class PStack{
    pvector<T> vec;
public:
    PStack(string fname):
        vec(fname)
    {/* void */};
    PStack(const PStack&) = delete; // Copy constructor

    void push(T val){
        vec.push_back(val);
    }

    T pop(){
        if(vec.size() == 0) throw("No elements left on the stack");
        T val = vec.back();
        vec.pop_back();
        return val;
    }

    int size(){ return vec.size();}
    void clear(){ vec.clear();}

    friend ostream& operator<<(ostream &os, PStack &stack){
        if(stack.size() == 0) return os;
        int i = 0;
        for(auto it = stack.vec.begin(); it != stack.vec.end(); it++){
            os << i++ << ": " << *it << endl;
        }
        return os;
    }
};

template <typename T>
class RPN{
    PStack<T> stack;
    string unprocessed_input;
public:
    bool finished;
    RPN<T>(string fname = "stack.txt"): stack(fname), finished(false) {};
    RPN<T>(const RPN<T>&) = delete;
    // TODO: Add destructor?

    void take_input();
    bool calculate();
};

template <typename T>
void RPN<T>::take_input(){
    unprocessed_input.clear();
    string input;
    cout << "Command: ";
    getline(cin, input);
    unprocessed_input.append(" ");
    unprocessed_input.append(input);
}

template <typename T>
bool RPN<T>::calculate(){
    char c;
    T num, a, b;

    stringstream is(unprocessed_input);

    while(is.good()){
        is >> c;  // Allows for n2 AND n 2
        try
        {
            if(c=='+' || c=='-' || c=='/' || c=='*'){
                if(stack.size() < 2){
                    cout << "Not enough numbers on the stack! " << endl;
                    return false;
                }
                b = stack.pop();
                a = stack.pop();
            }
            switch (c)
            {
            case 'q':
                finished = true;
                return false;
            case 'n':
                // TODO: If n is last char followed by nothing, num becomes 1
                is >> num;
                stack.push(num);
                break;
            case 'd':
                if(stack.size() == 0){
                    cout << "No number left on stack to delete!" << endl;
                    return false;
                }
                stack.pop();
                break;
            case '+':
                stack.push(a+b);
                break;
            case '-':
                stack.push(a-b);
                break;
            case '*':
                stack.push(a*b);
                break;
            case '/':
                stack.push(a/b);
                break;
            default:
                break;
            }
            c='\0';
        }
        catch(const std::exception& e)
        {
            cout << e.what() << '\n';
            return false;
        }
    }

    cout << stack;
    return true;
}

int main(){
    RPN<int> intRPN("int.txt");
    while(!intRPN.finished){
        intRPN.take_input();
        intRPN.calculate();
    }
    RPN<fraction> fracRPN("frac.txt");
    while(!fracRPN.finished){
        fracRPN.take_input();
        fracRPN.calculate();
    }
    return 0;
}