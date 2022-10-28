#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>


using namespace std;

class Stack{
    vector<double> stack;
public:
    Stack(){/* void */};
    Stack(const Stack&) = delete; // Copy constructor
    
    void push(double val){
        stack.push_back(val);
    }

    double pop(){
        if(stack.size() == 0) throw("No elements left on the stack");
        double val = stack.back();
        stack.pop_back();
        return val;
    }

    int size(){ return stack.size();}

    friend ostream& operator<<(ostream &os, Stack &stack){
        if(stack.size() == 0) return os;
        int i = 0;
        for(double val: stack.stack){
            os << i++ << ": " << val << endl;
        }
        return os;
    }
};

bool calculate(Stack &stack, stringstream &is){
    char c;
    double num; double a, b;

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
                return false;
            case 'n':
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
        }
    }

    return true;
}

int main(){
    Stack stack;

    string input;

    while(true){
        cout << "Command: ";
        getline(cin, input);

        stringstream is(input);
        calculate(stack, is);

        cout << stack;
    }


    return 0;
}