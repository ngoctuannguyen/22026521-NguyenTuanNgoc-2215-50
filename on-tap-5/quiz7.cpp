#include <bits/stdc++.h>

using namespace std;

char *s;

// void reverse(char *s) {
//     // Your code goes here
//     int strLen = strlen(s);
//     char* reverseString = new char[strLen];
//     char* reverseStringResult = reverseString;
//     for (char* p = &s[strLen - 1]; p >= &s[0]; p--) {
//         *reverseString = *p;
//         reverseString++;
//     }
//     *(reverseString + 1) = '\0';
//     s = reverseStringResult;
// }

void reverse(char *s) {
    // Your code goes here
    int strLen = strlen(s);
    string strResult = "";
    for (int i = strLen - 1; i >= 0; --i) {
        strResult += s[i];
    }
    for (int i = 0; i < strLen; ++i) {
        s[i] = strResult[i];
    }
}

int main()
{
    s = new char[50];
    cin >> s;
    reverse(s);
    cout << s;

    return 0;
}