inline void swap(int &a, int &b) {
    int c=a; a=b; b=c;
}

int gcd(int a, int b) {
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