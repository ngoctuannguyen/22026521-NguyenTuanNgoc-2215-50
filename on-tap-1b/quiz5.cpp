#include <bits/stdc++.h>

using namespace std;

int sum;
const double MAX = -1e18;
const double MIN = 1e18;
double min_res = MIN, max_res = MAX;

int main() {

    for (int i = 1; i <= 5; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << setprecision(2) << fixed << double(sum) / double(5);

    return 0;
}