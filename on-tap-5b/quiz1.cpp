#include <bits/stdc++.h>
using namespace std;

int count_adjacent_mines(vector<vector<char>>& board, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int idx = x + dx, idy = y + dy;
            if (idx >= 0 && idx < int(board.size()) && idy >= 0 && idy < int(board[0].size())) {
                if (board[idx][idy] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<char>> board(m, vector<char>(n));
    vector<vector<char>> result(m, vector<char>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '*') {
                result[i][j] = '*';
            } else {
                int minescount = count_adjacent_mines(board, i, j);
                result[i][j] = char(minescount + '0');
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}