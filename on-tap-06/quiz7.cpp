#include <bits/stdc++.h>

using namespace std;    

class Fraction {
    int a, b;
public:
    Fraction(int a = 1, int b = 1);
    friend ostream& operator<<(ostream& os, const Fraction& f);
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    void simplify();
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
};

Fraction::Fraction(int a, int b) {
    this->a = a;
    this->b = b;
}

ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.b == 0) {
        os << "invalid";
    }
    else {
        os << f.a << "/" << f.b;
    }
    return os;
}

Fraction Fraction::operator+(const Fraction& f) const {
    return Fraction(this->a * f.b + this->b * f.a, this->b * f.b);
}   

Fraction Fraction::operator-(const Fraction& f) const {
    return Fraction(this->a * f.b - this->b * f.a, this->b * f.b);
}

Fraction Fraction::operator*(const Fraction& f) const {
    return Fraction(this->a * f.a, this->b * f.b);
}

Fraction Fraction::operator/(const Fraction& f) const {
    return Fraction(this->a * f.b, this->b * f.a);
}

void Fraction::simplify() {
    int gcd = __gcd(this->a, this->b);
    this->a /= gcd;
    this->b /= gcd;
}

bool Fraction::operator>(const Fraction& f) const {
    Fraction f1 = *this;
    Fraction f2 = f;
    f1.simplify();
    f2.simplify();
    return (f1.a * f2.b) > (f1.b * f2.a);
}

bool Fraction::operator<(const Fraction& f) const {
    Fraction f1 = *this;
    Fraction f2 = f;
    f1.simplify();
    f2.simplify();
    return (f1.a * f2.b) < (f1.b * f2.a);
}

int main() {
    Fraction x(1, 3), y(1, 3);
    x = x + y;
    cout << x;
    return 0;
}
