#include <bits/stdc++.h>

using namespace std;

int number;
const double MAX = -1e18;
const double MIN = 1e18;
double min_res = MIN, max_res = MAX;

int main() {

    cin >> number;

    for (int i = 1; i <= number; ++i) {
        double x;
        cin >> x;
        max_res = max(max_res, x);
        min_res = min(x, min_res);
    }

    cout << max_res << endl << min_res;

    return 0;
}