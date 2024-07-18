#include <bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int numerator, int denominator) {
    if (numerator < denominator) {
        swap(numerator, denominator);
    }
    if (denominator != 0) {
        return gcd(denominator, numerator % denominator);
    }
    else return numerator;
}

int main() {
    
    int numerator, denominator;

    cin >> numerator >> denominator;
    
    bool positive = false;
    
    if ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0)) {
        positive = true;
    }
    
    numerator = abs(numerator);
    denominator = abs(denominator);
    
    int gcd_ = gcd(numerator, denominator);
    
    numerator /= gcd_;
    denominator /= gcd_;
    
    if (!positive) {
        cout << -numerator;
    }
    else cout << numerator;
    
    if (denominator != 1)
        cout << "/" << denominator;

    return 0;
}