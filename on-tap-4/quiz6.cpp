#include <bits/stdc++.h>

using namespace std;

string checkPalidrome(string strInput) {
    for (int i = 0; i < strInput.length() / 2; ++i) {
        if (strInput[i] != strInput[strInput.length() - 1 - i]) {
            return "No";
        }
    }
    return "Yes";
}

int main() {

    string str;

    cin >> str;

    cout << checkPalidrome(str); 

    return 0;
}