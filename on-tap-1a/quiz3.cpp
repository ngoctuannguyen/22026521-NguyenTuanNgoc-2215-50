#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

    int x0, v0, x1, v1;

    cin >> x0 >> v0 >> x1 >> v1;

    if ((x0 - x1) % (v1 - v0) == 0 && (x0 - x1) / (v1 - v0) >= 0) {
        cout << "YES";
    }
    else cout << "NO";

    return 0;
}