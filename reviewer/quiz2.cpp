#include <bits/stdc++.h>

using namespace std;

set<vector<int>> st;

int* genNumbers(int N) {
    int* a = new int[N];
    for (int i = 0; i < N; ++i) {
        a[i] = abs(rand()) % 50;
    }
    return a;
}

void printNumbers(int *a, int N) {

    int prev[3] = {-1, -1, -1};

    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k)  {
                if ((a[i] + a[j] + a[k]) % 25 == 0) {
                    vector<int> v = {a[i], a[j], a[k]};
                    // sort(v.begin(), v.end());
                    //st.insert(v);
                    //if (prev[0] != v[0] || prev[1] != v[1] || prev[2] != v[2]) {
                    for (int id = 0; id < 3; ++id) {
                        cout << v[id] << " ";
                        prev[id] = v[id];
                    }
                    cout << endl;
                   // }
                    //cout << a[i] << " " << a[j] << " " << a[k] << endl;
                }
            }
            // cout << endl;
        }
    }
}

int main() {
    int seed = 1; //Test cases use different seed numbers 
    srand(seed);
    int n;
    cin >> n;
    int *a = genNumbers(n);
    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

    cout << endl;

    printNumbers(a, n);
}