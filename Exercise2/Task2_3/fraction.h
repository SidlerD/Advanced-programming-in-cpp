#ifndef FRACTION_H
#define FRACTION_H

#include <sstream>
#include <iostream>

inline void check_char(std::istream &is, char ch) {
    char c; is >> c; if(c!=ch) { is.putback(c); is.setstate(std::ios::badbit); }
}

inline void swap(int &a, int &b) {
    int c=a; a=b; b=c;
}

inline int gcd(int a, int b) {
    if(a<0) a *= -1;
    if(b<0) b *= -1;
    if (a<b) {
        swap(a, b);
    }
    while (b!=0) {
        a=a-b;
        if (a<b) {
            swap(a, b);
        }
    }
    return a; 
}

class fraction { // type definition
    int num;
    int denom;
    std::ostringstream sstr;
public:
    fraction(int c=0, int d=1) :
    num(c), denom(d)
    { sstr = std::ostringstream(); }

    // Copy constructor, needed for fraction * fraction
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

    friend std::ostream& operator<<(std::ostream &os, const fraction &f){
        os << "(" << f.num << "/" << f.denom << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, fraction &f){
        fraction g; fraction h; char c;
        check_char(is, '('); is >> g.num;
        check_char(is, '/'); is >> g.denom;
        check_char(is, ')'); if(is) f=g;

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

#endif