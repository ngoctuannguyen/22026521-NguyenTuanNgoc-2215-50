#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    map<int, int> appearCount;
    int arr[n + 1], brr[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        appearCount[arr[i]] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> brr[i];
        if (appearCount[brr[i]]) {
            appearCount[brr[i]] = 2;
        }
        else {
            appearCount[brr[i]] = 1;
        }
    }

    int sumDiff = 0;

    for (auto it : appearCount) {
        if (it.second == 1) {
            sumDiff += it.first;
        }
    }

    cout << sumDiff;

    return 0;
}