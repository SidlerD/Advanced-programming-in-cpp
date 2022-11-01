#pragma once
#include "pstack.h"
#include <stdexcept>

template <typename T>
class rpn{
    pstack<T> stack;
    std::string unprocessed_input;

public:
    bool finished;
    rpn<T>(std::string fname = "stack.txt"): stack(fname), finished(false) {};
    rpn<T>(const rpn<T>&) = delete;

    void take_input(){
        unprocessed_input.clear();
        std::string input;
        std::cout << "Command: ";
        getline(std::cin, input);
        unprocessed_input.append(" ");
        unprocessed_input.append(input);
    }
    bool calculate() {
        char c;
        T num, a, b;

        std::stringstream is(unprocessed_input);

        while(is.good()){
            is >> c;  // Allows for n2 AND n 2
            try
            {
                if(c=='+' || c=='-' || c=='/' || c=='*'){
                    if(stack.size() < 2){
                        std::cout << "Not enough numbers on the stack! " << std::endl;
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
                        std::cout << "No number left on stack to delete!" << std::endl;
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
                case 'm':
                    if(stack.size() < 2) break;
                    std::cout << "Min of top of stack is: " << stack.min() << std::endl;
                    break;
                default:
                    break;
                }
                c='\0';
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                return false;
            }
        }

        std::cout << stack;
        return true;
    }

    void run(){
        while(!finished){
            take_input();
            calculate();
        }
    }
};
