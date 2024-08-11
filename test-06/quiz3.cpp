struct Complex {
    // your code goes here
    // Cac bien thanh vien
    int a;
    int b;
    // your code goes here
    // Hai ham khoi tao
    
    Complex() {
        a = 0;
        b = 0;
    }
    
    Complex(int _a, int _b) {
        a = _a;
        b = _b;
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
        if (a != 0) {
            cout << a;
        }
        if (b < 0) {
            if (b != -1) {
                cout << b << "i";
            }
            else cout << "-i";
        }
        else if (b > 0) {
            if (b != 1) {
                cout << "+" << b << "i";
            }
            else cout << "+i";
        }
        cout << endl;
    }
};

Complex add(Complex a, Complex b) {
    // your code goes here
    Complex sum;
    sum.a = a.a + b.a;
    sum.b = a.b + b.b;
    return sum;
}