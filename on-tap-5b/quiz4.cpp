#include <bits/stdc++.h>
using namespace std;

void createMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    
    int i = 0;
    int j = n / 2;
    
    for (int num = 1; num <= n * n; ++num) {
        magicSquare[i][j] = num;
        
        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;
        
        if (magicSquare[next_i][next_j]) {
            i = (i + 1) % n;
        } else {
            i = next_i;
            j = next_j;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    createMagicSquare(n);
    return 0;
}