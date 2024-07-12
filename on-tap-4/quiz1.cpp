#include <bits/stdc++.h>

using namespace std;

int arr[100005] = {0};
int sum[100001];

int main() {

    int arraySize;

    cin >> arraySize;

    for (int i = 1; i <= arraySize; ++i) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + arraySize + 1);

    int timeWait = 0;

    for (int i = 1; i <= arraySize; ++i) {
        sum[i] = sum[i - 1] + arr[i - 1];
        timeWait += sum[i];
        // cout << sum[i] << " ";
    }

    cout << timeWait;

    return 0;
}