#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
long long numOfTest, min_absolute = INF;
long long arr[100001];

int main() {

    cin >> numOfTest;

    for (int i = 1; i <= numOfTest; ++i) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + numOfTest + 1);

    for (int i = 2; i <= numOfTest; ++i) {
        min_absolute = min(min_absolute, abs(arr[i] - arr[i - 1]));
        // cout << min_absolute;
    }

    if (numOfTest == 1) {
        cout << arr[1];
    }
    else cout << min_absolute;

    return 0;
}