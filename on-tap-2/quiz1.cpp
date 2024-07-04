#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000000;

int preNumber;

int main() {

    int number;

    while (cin >> number) {
        if (preNumber != number) {
            cout << number << " ";
            preNumber = number;
        }
        if (number < 0) {
            break;
        }
    }
    
    return 0;
}