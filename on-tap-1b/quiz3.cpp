#include <bits/stdc++.h>

using namespace std;

int number;

int main() {

    cin >> number;

    if (number < 2) {
        cout << "no";
        return 0;
    }
    else {
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                cout << "no";
                return 0;
            }
        }
    }

    cout << "yes";

    return 0;
}