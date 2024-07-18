#include <bits/stdc++.h>

using namespace std;

int countDivisor(int num) {
    int count = 0;

    int numberMirror = num;

    while (numberMirror) {
        if (numberMirror % 10 && num % (numberMirror % 10) == 0)
            count++;
        numberMirror /= 10;
    }

    return count;
}

int main() {

    int testCase;

    cin >> testCase;

    while (testCase--) {
        int number;
        cin >> number;
        cout << countDivisor(number) << endl;
    }

    return 0;
}