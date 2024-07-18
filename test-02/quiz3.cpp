#include <bits/stdc++.h>

using namespace std;

int magicSquare[11][11];

int generateMagicSquare(int m, int n) {

    int count = 1;
    int srcRow = 1, destRow = m;
    int srcCol = 1, destCol = n;
    while (srcRow <= destRow && srcCol <= destCol) {
        for (int i = srcCol; i <= destCol; ++i){
            magicSquare[srcRow][i] = count;
            count++;
            if (count > n * m) {
                return 0;
            }

        }
        srcRow++;

        for (int i = srcRow; i <= destRow; ++i){
            magicSquare[i][destCol] = count;
            count++;
            if (count > n * m) {
                return 0;
            }

        }
        destCol--;

        for (int i = destCol; i >= srcCol; --i){
            magicSquare[destRow][i] = count;
            count++;
           if (count > n * m) {
                return 0;
            }

        }
        destRow--;

        for (int i = destRow; i >= srcRow; --i){
            magicSquare[i][srcCol] = count;
            count++;
            if (count > n * m) {
                return 0;
            }

        }
        srcCol++;
        
    }
    return 0;
}

void printMatrix(int m, int n) {

    //vector<vector<int>> magicSquare = generateMagicSquare(N);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
   
    int n, m;
    
    cin >> m >> n;

    generateMagicSquare(m, n);

    printMatrix(m, n);

    return 0;
}
