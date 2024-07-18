#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMagicSquare(int N) {

    vector<vector<int>> magicSquare(N, vector<int>(N, 0));

    int num = 1;
    int i = 0, j = N / 2;

    while (num <= N * N) {

        magicSquare[i][j] = num++;

        int newi = (i - 1 + N) % N;
        int newj = (j + 1) % N;

        if (magicSquare[newi][newj] != 0) {
            i = (i + 1) % N;
        } else {
            i = newi;
            j = newj;
        }
    }

    return magicSquare;
}

void printMatrix(int N) {

    vector<vector<int>> magicSquare = generateMagicSquare(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
   
    int n;
    
    cin >> n;

    printMatrix(n);

    return 0;
}
