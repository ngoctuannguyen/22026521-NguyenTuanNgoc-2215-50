#include <bits/stdc++.h>

using namespace std;

int** transpose(int** matrix, int nRows, int nCols) {

    int** transposedMatrix = new int*[nCols];

    for(int i = 0; i < nCols; i++) {
        transposedMatrix[i] = new int[nRows];
    }

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    
    return transposedMatrix;

}

int main()
{
    int nRows, nCols;

    cin >> nRows >> nCols;
    
    int** matrix = new int*[nRows];
    for(int i = 0; i < nRows; i++) {
        matrix[i] = new int[nCols];
    }

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int** transposeMatrix = transpose(matrix, nRows, nCols);

    for (int i = 0; i < nCols; ++i) {
        for (int j = 0; j < nRows; ++j) {
            cout << transposeMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}