#include <bits/stdc++.h>

using namespace std;

char *s;

void rFilter(char* s) {
    //*(s) = '_';
    // *(s + 1) = '\0';

    int strLen = strlen(s);

    for (char* p = &s[strLen - 1]; p >= &s[0]; p--) {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))) {
            *p = '_';
        }
        else break;
    }
}

int main()
{
    s = new char[50];
    cin >> s;
    rFilter(s);
    cout << s;

    return 0;
}