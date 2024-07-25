#include <bits/stdc++.h>

using namespace std;

struct Complex {
    // your code goes here
    // Cac bien thanh vien
    int a;
    int b;
    // your code goes here
    // Hai ham khoi tao
    
    Complex(int a_, int b_) {
        a = a_;
        b = b_;
    }
    
    Complex() {
        a = 0;
        b = 0;
    }
 
    double abs() {
        // your code goes here
        return sqrt(a * a + b * b);
    }
    
    void print() {
        // your code goes here
        if (a == b && b == 0) {
            cout << 0 << endl;
            return;
        }
        if (a != 0)
            cout << a;
        if (b < 0) {
            if (b < -1) {
                cout << b << "i" << endl;
            }
            else cout << "-i" << endl;
        }
        else if (b > 0) {
            if (b == 1) {
                cout << "+i" << endl;
            }
            else cout << "+" << b << "i" << endl;
        }
        else {
            cout << endl;
        }
    }
};

Complex add(Complex a, Complex b) {
    // your code goes here
    Complex sum;
    sum.a = a.a + b.a;
    sum.b = a.b + b.b;
    return sum;
}

int main() {
    Complex a, b, sum;
    int a_, b_;
    cin >> a_ >> b_;
    a = Complex(a_, b_);
    cin >> a_ >> b_;
    b = Complex(a_, b_);
    sum = add(a, b);
    sum.print();
    return 0;
}