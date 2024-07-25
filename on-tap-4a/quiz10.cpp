#include <bits/stdc++.h>

using namespace std;

int prime[1000001];

void eratosthense() {

    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i * i <= 1000000; ++i) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= 1000000; j += i) {
                if (prime[j] == 0)
                    prime[j] = i;
                prime[i] = i;  
            }
        }
    }
}

void primeFactor(int n) {

    int prev = prime[n];
    int count = 0;

    while (n != 1) {
        //cout << prime[n] << "\n";
        if (prev != prime[n]) {
            cout << prev << " " << count << endl;
            prev = prime[n];
            count = 0;
        }
        count++;
        n = n / prime[n];
    }

    cout << prev << " " << count << endl;
}

int main() {
    
   
    int n;

    cin >> n;

    eratosthense();

    primeFactor(n);

    return 0;
}