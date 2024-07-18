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
    
    num1 = abs(num1);
    num2 = abs(num2);
    
    if (num1 == 0 || num2 == 0) {
        cout << 0;
    }
    else cout << num1 / gcd(num1, num2) * num2;

    return 0;
}