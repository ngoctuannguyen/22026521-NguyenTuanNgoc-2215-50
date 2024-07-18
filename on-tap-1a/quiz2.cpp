#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

    int a1, b1, c1, a2, b2, c2;
    int D, D_x, D_y;

    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    D = a1 * b2 - b1 * a2;
    D_x = c1 * b2 - c2 * b1;
    D_y = a1 * c2 - a2 * c1;

    if (D != 0) {
        cout << "x = " << D_x / D << ", y = " << D_y / D;
    }
    else {
        if (D_x != 0 || D_y != 0) {
            cout << "Vo nghiem";
        }
        if (D_x == D && D == D_y) {
            cout << "Vo so nghiem";
        } 
    }


    return 0;
}