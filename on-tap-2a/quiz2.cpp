#include <bits/stdc++.h>

using namespace std;

vector<int> rowPresentation(int startElement, int sizeOfMatrix) {
    vector<int> rowVector = {};
    for (int i = startElement; i <= sizeOfMatrix + startElement - 1; ++i) {
        if (i % sizeOfMatrix != 0) {
            rowVector.push_back(i % sizeOfMatrix);
        }
        else rowVector.push_back(sizeOfMatrix);
    }
    return rowVector;
}

void printMatrix(int sizeOfMatrix) {
    vector<vector<int>> answerMatrix;

    for (int i = 1; i <= sizeOfMatrix; ++i) {
        answerMatrix.push_back(rowPresentation(i, sizeOfMatrix));
    }

    for (int i = 0; i < sizeOfMatrix; ++i) {
        for (int j = 0; j < sizeOfMatrix; ++j) {
            cout << answerMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int sizeOfMatrix;

    cin >> sizeOfMatrix;

    printMatrix(sizeOfMatrix);

    return 0;
}