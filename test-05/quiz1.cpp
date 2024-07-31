#include <bits/stdc++.h>

using namespace std;

int* getPointerToTen() {
    int* pInt = new int;
    *pInt = 10;
    return pInt;
}

int main() {
    int* pInt = getPointerToTen();
    cout << *pInt << endl;
    delete pInt;
    return 0;
}

