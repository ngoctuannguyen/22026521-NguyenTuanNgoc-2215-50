#include <bits/stdc++.h>

using namespace std;

int arr[10001];
map<int, int> checkAppear;
// int index[10001];

int binarySearch(int left, int right, int arr[], int value) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) >> 1;
    if (arr[mid] < value) {
        return binarySearch(mid + 1, right, arr, value);
    }
    if (arr[mid] > value) {
        return binarySearch(left, mid - 1, arr, value);
    }
    return mid;
}

vector<vector<int>> checkZeroTriple(int N) {
    
    vector<vector<int>> ans = {};
    
    for (int i = 1; i < N; i++) {
        if (i > 1 && arr[i] == arr[i-1]) {
            continue;
        }
        
        int j = i + 1;
        int k = N;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;

                while (arr[j] == arr[j-1] && j < k) {
                    j++;
                }
            }
        }
    }

    return ans;
}

int main() {

    int numElements;

    cin >> numElements;

    for (int i = 1; i <= numElements; ++i) {
        cin >> arr[i];
        checkAppear[arr[i]]++;
    }

    sort(arr + 1, arr + numElements + 1);

    vector<vector<int>> result = checkZeroTriple(numElements);

    for (int i = 0; i < int(result.size()); ++i) {
        for (int j = 0; j < int(result[i].size()); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
