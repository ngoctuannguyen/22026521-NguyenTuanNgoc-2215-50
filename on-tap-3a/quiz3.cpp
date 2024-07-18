#include <bits/stdc++.h>

using namespace std;

void binaryGen(int n, string str) {
    if (n == int(str.length())) {
        cout << str << endl;
        return;
    }
    binaryGen(n, str + "0");
    binaryGen(n, str + "1");
}

int main() {

    int n;

    cin >> n;

    binaryGen(n, "");

    return 0;
}
