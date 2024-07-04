#include<bits/stdc++.h>

#define ll long long

using namespace std;

string arr[100];

int main() {

    int a, b, c;

    double x, y;

    cin >> a >> b >> c;

    int delta = b * b - 4 * a * c;

    if (delta > 0) {
        x = (-b + sqrt(delta)) / (2 * a);
        y = (-b - sqrt(delta)) / (2  *a);
        cout << setprecision(2) << fixed << min(x, y) << "\n";
        cout << setprecision(2) << fixed << max(x, y) << "\n";
    }
    else if (delta == 0) {
        cout << setprecision(2) << fixed << double(-b / (2  * a));
    }
    else {
        double sqrt_delta = sqrt(abs(delta));
        cout << setprecision(2) << fixed << double(-b) / double(2  * a) << " ";
        cout << setprecision(2) << fixed << -sqrt_delta / 2 << "\n";
        cout << setprecision(2) << fixed << double(-b) / double(2  * a) << " ";
        cout << setprecision(2) << fixed << sqrt_delta / 2;
    }
    

    return 0;
}