#include <bits/stdc++.h>

using namespace std;

void update(int* a, int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);
    *a = sum;
    *b = diff;
}

int main() {
    
    int a, b;

    cin >> a >> b;

    update(&a, &b);

    cout << a << "\n" << b << "\n";

    return 0;
}