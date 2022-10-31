#include "Task2.h"
#include <iostream>
#include <sstream>

using namespace std;

void check_char(istream &is, char ch) {
    char c; is >> c; if(c!=ch) { is.putback(c); is.setstate(ios::badbit); }
}

class fraction { // type definition
    int num;
    int denom;
    ostringstream sstr;
public:
    fraction(int c=0, int d=1) :
    num(c), denom(d)
    { sstr = ostringstream(); }

    // Copy constructor, needed for fraction * fraction
    // TODO: Shouldn't this be generated automatically?
    fraction(const fraction &f) : num(f.num), denom(f.denom) { /*void*/ }

    fraction &operator=(fraction b) {
        num = b.num;
        denom = b.denom;
        return *this;
    }

    fraction operator*(fraction o) {
        int f1 = gcd(num, o.get_denominator());
        int f2 = gcd(o.get_numerator(), denom);
        return fraction((num/f1) * (o.get_numerator()/f2),
        (denom/f2) * (o.get_denominator()/f1));
    }
    fraction operator*(int i) {
        return fraction(num*i, denom*i);
    }

    fraction operator/(fraction o) {
        return *(this) * fraction(o.get_denominator(), o.get_numerator());
    }
    fraction operator/(int i) {
        return fraction(num/i, denom/i);
    }

    // https://www.allmathwords.org/en/f/fractionrules.html
    fraction operator+(fraction o) {
        fraction f = fraction(
            num * o.get_denominator() + denom * o.get_numerator(),
            denom * o.get_denominator()
        );
        return f / gcd(f.num, f.denom);
    }

    fraction operator-(fraction o) {
        fraction f =  fraction(
            num * o.get_denominator() - denom * o.get_numerator(),
            denom * o.get_denominator()
        );
        int g = gcd(f.num, f.denom);
        return f / (g==0 ? 1 : g);
    }

    friend ostream& operator<<(ostream &os, const fraction &f){
        os << "(" << f.num << "/" << f.denom << ")";
        return os;
    }

    friend istream &operator>>(istream &is, fraction &f) {
        fraction g; fraction h; char c;
        check_char(is, '('); is >> g.num;
        check_char(is, '/'); is >> g.denom;
        check_char(is, ')'); if(is) f=g;

        // is >> c;
        is.get(c);
        if(!is.good()){ is.clear(); return is;}
        switch (c)
        {
        case '+':
            is >> h;
            f = g + h;
            break;
        case '-':
            is >> h;
            f = g - h;
            break;
        case '*':
            is >> h;
            f = g * h;
            break;
        case '/':
            is >> h;
            f = g / h;
            break;
        case '\n':
            break;
        default:
            break;
        }
        return is;
    }

    int get_numerator(void) {
        return num;
    }
    void set_numerator(int c) {
        num=c;
    }
    int get_denominator(void) {
        return denom;
    }
    int set_deniminator(int d){
        denom = d;
    }
};

int main(){
    fraction f1 = fraction(1, 4);
    fraction f2 = fraction(1, 5);

    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f2 << " + " << f1 << " = " << (f2 + f1) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f2 << " - " << f1 << " = " << (f2 - f1) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;

    while(true){
        fraction f3;
        cout << "Enter a fraction / two fractions separated by an operator: ";
        cin >> f3;
        cout << endl << f3 << endl;
    }

    return 0;
}