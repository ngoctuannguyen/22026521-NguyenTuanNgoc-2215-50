#include <bits/stdc++.h>

using namespace std;

int n, m;

//int arrInput[100001], arrQuery[100001];

bool binarySearch(int left, int right, int arr[], int value) {
    if (left > right) 
        return false;
    int mid = (left + right) >> 1;
    if (arr[mid] == value) 
        return true;
    if (arr[mid] < value) {
        return binarySearch(mid + 1, right, arr, value);
    }
    if (arr[mid] > value) {
        return binarySearch(left, mid - 1, arr, value);
    }
    return false;
}

int main() {

    cin >> n >> m;
    
    int arrInput[n + 1], arrQuery[m + 1];
    

    for (int i = 1; i <= n; ++i) {
        cin >> arrInput[i];
    }

    for (int i = 1; i <= m; ++i) {
        cin >> arrQuery[i];
        if (binarySearch(1, n, arrInput, arrQuery[i])) 
            cout << "YES ";
        else cout << "NO ";
    }

    return 0;
}
