#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;

    cin >> m >> n;

    map<int, int> appearCount;
    int arr[m + 1];
    int brr[n + 1];

    for (int i = 1; i <= m; ++i) {
        cin >> arr[i];
        appearCount[arr[i]]++;
    }

    int count = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> brr[i];
        if (appearCount[brr[i]]) {
            count++;
        }
    }
    
    if (count == n) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}