#include <bits/stdc++.h>

using namespace std;

bool conditionCheck(int n, int m, string str) {
    for (int i = 0; i < int(str.length()); ++i) {
        if (str[i] == '0')
            n--;
        else m--;
    }
    
    if (n == 0 && m == 0)
        return true;
    return false;
}

void binaryGen(int n, int m, string str) {
    if (int(str.length()) == n + m) {
        if (conditionCheck(n, m, str))
            cout << str << endl;
        return;
    }
    binaryGen(n, m, str + "0");
    binaryGen(n, m, str + "1");
}

int main() {

    int n, m;

    cin >> n >> m;

    binaryGen(n, m, "");

    return 0;
}
