#include <bits/stdc++.h>

using namespace std;

int arr[100005] = {0};

bool checkPalidrome(string strInput) {
    for (int i = 0; i < int(strInput.length() / 2); ++i) {
        if (strInput[i] != strInput[strInput.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void cumulativePalidromeNumberArray() {
    
    arr[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        if (checkPalidrome(to_string(i))) {
            arr[i] = arr[i - 1] + 1;
        }
        else arr[i] = arr[i - 1]; 
    }  
}

int query(int arr[], int left, int right) {
    if (left == 0)
        return arr[right];
    return arr[right] - arr[left - 1];
}

int main() {

    int testCase, left, right;

    cin >> testCase;

    cumulativePalidromeNumberArray();

    while (testCase--) {
        cin >> left >> right;
        cout << query(arr, left, right) << endl;
    }

    return 0;
}