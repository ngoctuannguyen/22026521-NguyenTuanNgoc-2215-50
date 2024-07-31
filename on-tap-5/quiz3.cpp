#include <iostream>

using namespace std;

int* getPointerToArray(int n) {
    int* arr = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}