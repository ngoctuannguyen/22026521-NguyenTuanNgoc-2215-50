#include<bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int numerator, int denominator) {
    if (denominator != 0) {
        return gcd(denominator, numerator % denominator);
    }
    else return numerator;
}

int main() {
    
    int numerator, denominator;

    cin >> numerator >> denominator;

    bool swapCheck = false;

    if (numerator < denominator) {
        swapCheck = true;
        swap(numerator, denominator);
    }

    int gcd_ = gcd(numerator, denominator);

    if (swapCheck) {
        cout << denominator / gcd_ << "/" << numerator / gcd_;
    }
    else cout << numerator / gcd_ << "/" << denominator / gcd_;

    return 0;
}