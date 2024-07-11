#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[20][20];
char answer[20][20];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int count = 0;
            if (arr[i][j] != '*') {
                if (arr[i + 1][j] == '*') 
                    count++;
                if (arr[i + 1][j - 1] == '*') 
                    count++;
                if (arr[i + 1][j + 1] == '*') 
                    count++;
                if (arr[i][j + 1] == '*') 
                    count++;
                if (arr[i][j - 1] == '*') 
                    count++;
                 if (arr[i - 1][j] == '*') 
                    count++;
                if (arr[i- 1][j - 1] == '*') 
                    count++;
                if (arr[i - 1][j + 1] == '*') 
                    count++;
                answer[i][j] = char(count + '0');
            }
            else answer[i][j] = '*';
            
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}