#include <bits/stdc++.h>

using namespace std;

int** inputMatrix(int nRows, int nCols) {
    int** matrix = new int*[nRows];

    for(int i = 0; i < nCols; i++) {
        matrix[i] = new int[nCols];
    }

    for (int* i = matrix[0]; i < (matrix[0] + nRows); ++i) {
        for (int* j = i; j < (i + nCols); ++j) {
            cin >> *j;
        }
    }
    return matrix;
}

int** transpose(int** matrix, int nRows, int nCols) {
    
    int** transposeMatrix = new int* [nCols];
    for (int i = 0; i < nCols; ++i) {
        transposeMatrix[i] = new int [nRows];
        for (int j = 0; j < nRows; ++j) {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    return transposeMatrix;
}

void printMatrix(int** matrix, int nRows, int nCols) {

    for (int* i = matrix[0]; i < (matrix[0] + nRows); ++i) {
        for (int* j = i; j < (i + nCols); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
}

int main() {
    int nRows, nCols;
    cin >> nRows >> nCols;
    
    int** matrix = inputMatrix(nRows, nCols);
    
    printMatrix(matrix, nRows, nCols);
    
    int** transposeMatrix = transpose(matrix, nRows, nCols);
    
    printMatrix(transposeMatrix, nCols, nRows);
    
    return 0;
}