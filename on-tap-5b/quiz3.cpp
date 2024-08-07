#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int m, n, k;

void printMap(vector<vector<char>>& mineMap) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mineMap[i][j];
        }
        cout << endl;
    }
}

void printStatus(vector<vector<int>>& status) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << status[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int countMines(vector<vector<char>>& mineMap, int x, int y) {
    int count = 0;
    int m = int(mineMap.size());
    int n = int(mineMap[0].size());
    for (int i = 0; i < 8; ++i) {
        int idx = x + dx[i];
        int idy = y + dy[i];
        if (isValid(idx, idy, m, n) && mineMap[idx][idy] == 'M') {
            ++count;
        }
    }
    return count;
}

int main() {

    cin >> m >> n >> k;
    
    vector<vector<char>> mineMap(m, vector<char>(n));
    vector<vector<int>> status(m, vector<int>(n, -1));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mineMap[i][j];
        }
    }

    // printMap(mineMap);

    int x, y;
    
    while (cin >> x >> y) {
        if (mineMap[x][y] == 'M') {
            cout << "YOU'RE DEAD!" << endl;
            printMap(mineMap);
            break;
        } else {
            status[x][y] = countMines(mineMap, x, y);
            printStatus(status);
        }
    }
    
    return 0;
}
