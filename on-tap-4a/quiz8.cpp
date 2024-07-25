#include <bits/stdc++.h>

using namespace std;

bool consequent(int a[], int b[], int n, int m) {
    
    int i = 1, j = 1;
    int count = 0;

    while (i <= m && j <= n) {
        if (a[j] == b[i]) {
            count++;
            i++;
            j++;
        }
        else {
            count = 0;
            i++;
            j = 1;
        }
        if (count == n) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;

    cin >> n;
   
    int a[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];   
    }
    
    cin >> m;

    int b[m + 1];

    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    cout << (consequent(a, b, n, m) ? "YES" : "NO");

    return 0;
}