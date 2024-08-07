#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {

    int triangle[n][n];

    for (int i = 0; i <= n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    pascalTriangle(n);
    return 0;
}