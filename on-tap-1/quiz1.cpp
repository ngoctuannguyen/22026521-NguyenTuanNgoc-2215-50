#include<bits/stdc++.h>

#define ll long long

using namespace std;

int pythagoras(int a, int b, int c) {
    if (a * a + b * b == c * c) {
        return 1;
    }
    return 0;
}

int deu(int a, int b, int c) {
    if (a == b && b == c) {
        return 1;
    }
    return 0;
}

int can(int a, int b, int c) {
    if (a == b || a == c || b == c) {
        return 1;
    }
    else return 0;
}

int main() {

    int a, b, c;

    cin >> a >> b >> c;

    if (a + b > c && b + c > a && c + a > b) {
        cout << a + b + c << "\n";
        if (pythagoras(a, b, c) || pythagoras(a, c, b) || pythagoras(c, b, a)) {
            cout << "vuong";
        }
        else if (deu(a, b, c)) {
            cout << "deu";
        } 
        else if (can(a, b, c)) {
            cout << "can";
        }
        else cout << "thuong";
    }
    else {
        cout << "Invalid";
    }


    return 0;
}