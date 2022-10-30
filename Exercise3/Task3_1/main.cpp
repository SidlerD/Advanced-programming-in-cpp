#include <iostream>
#include <vector>
#include "dumb_pointer.h"
#include "smart_pointer.h"

template <typename T>
void printvec(std::vector<T> vec){
    auto start = vec.begin(), end = vec.end();
    for(; start<end; ++start ){
        std::cout << *start << ", ";
    }
    std::cout << std::endl;
}

class Object{
    int prop;
public:
    Object(int i): prop(i){};
    std::string method1(){ return "method1"; }
    std::string method2(){ return "method2"; }
    std::string method3(){ return "method3"; }

    friend std::ostream& operator<<(std::ostream& os, Object o){
        return os << o.prop;
    }
};

void dumb_pointer_examples(){
    int num = 1;
    dumb_pointer<int> p(num);

    std::vector<int> vec;
    vec.push_back(1); 


    dumb_pointer<std::vector<int>> vecp(vec);
    (*vecp).push_back(-3);
    vecp->push_back(4);

    printvec(*vecp);
}

template <typename T>
void print(smart_pointer<T> p) { std::cout << p.counter() << ": " << *p << std::endl; }

void smart_pointer_examples(){
    Object *o1=new Object(1); // let's create our 1st object
    Object *o2=new Object(2); // let's create our 2nd object
    smart_pointer<Object> p(o1); // ref counter is 1 for 1st object
    std::cout << "p.counter: " << p.counter() << std::endl; // displays 1
    smart_pointer<Object> q(p); // another smart pointer that points to o1 (overload copy constructor)
    std::cout << "p(q), then p.counter: " << p.counter() << std::endl; // displays 2 (two smart pointers refer to o1)
    std::cout << "q.counter: " << q.counter() << std::endl; // displays 2 (two smart pointers refer to o1)
    smart_pointer<Object> r(o2); // ref counter is 1 for 2nd object
    std::cout << "r(o2).counter: " << r.counter() << std::endl; // displays 1
    q=r; // decrease counter for 1st object and
    // increase counter for 2nd object (overload assignment operator)
    std::cout << "q=r, then p.cnt, q.cnt, r.cnt: " << std::endl;
    std::cout << p.counter() << std::endl; // displays 1
    std::cout << q.counter() << std::endl; // displays 2
    std::cout << r.counter() << std::endl; // displays 2
    print(p); // displays 2, and the 1st object, don't delete the object pointed to by p
    print(q); // displays 3, and the 2nd object, don't delete the object pointed to by q
    print(r); // displays 3, and the 2nd object, don't delete the object pointed to by r
    std::cout << *p << *r << std::endl; // display 1st and 2nd object (overload operator*)
    // std::cout << p->method1() << q->method2() << r->method3() << std::endl;
    // invoke method1 on 1st object and
    // invoke method2 on 2nd object and
    // invoke method3 on 2nd object (overload operator->)
}

int main(){
    smart_pointer_examples();
    // std::string h("hello");
    // smart_pointer<std::string> p(&h);
    // std::cout << "p: " << p.counter();
    // smart_pointer<std::string> q(p);
    // std::cout << ", q: " << q.counter() << std::endl;

    return 0;
}