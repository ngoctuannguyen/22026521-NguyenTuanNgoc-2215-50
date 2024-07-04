#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    
    int number;
    
    cin >> number;
    
    if (sqrt(number) * sqrt(number) == number) {
        cout << "YES";
    }
    else cout << "NO";
    
    return 0;
}