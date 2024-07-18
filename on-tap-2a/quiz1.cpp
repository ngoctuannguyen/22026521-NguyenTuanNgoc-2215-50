#include <bits/stdc++.h>

using namespace std;

int maxLen(int n, int arr[]) {
    int maxLen = 0;
    int start = 1;
    for (int i = 1; i <= n; ++i) {

        while (arr[i] - arr[start] > 1 && start <= n)
            start++;

        if (arr[i] - arr[start] <= 1) {
            maxLen = max(maxLen, i - start + 1);
        }
    }
    return maxLen;
}

int main() {
    int n;
    
    // cin >> n;

    // int arr[n + 1];

    // for (int i = 1; i <= n; ++i) {
    //     cin >> arr[i];
    // }

    // sort(arr + 1, arr + n + 1);

    // cout << maxLen(n, arr);

    cout << time(0);

    return 0;
}
