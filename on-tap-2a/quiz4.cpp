#include<bits/stdc++.h>

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
    
    int num1, num2;
    
    cin >> num1 >> num2;
    
    cout << gcd(num1, num2);

    return 0;
}