#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    map<int, int> appearCount;
    int arr[n + 1];
    int maxAppear = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        appearCount[arr[i]]++;
        maxAppear = max(maxAppear, appearCount[arr[i]]);
    }

    for (auto it = appearCount.begin(); it != appearCount.end(); ++it) {
        if (it->second == maxAppear) {
            cout << it->first << endl;
        }
    }

    return 0;
}