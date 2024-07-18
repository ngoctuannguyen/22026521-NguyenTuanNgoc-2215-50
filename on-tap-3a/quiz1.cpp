#include <bits/stdc++.h>

using namespace std;

int isPrime[1000001];
int arr[1000001];

void eratosthenes() {
    isPrime[0] = 1;
    isPrime[1] = 1;
    for (int i = 1; i * i <= 1000000; ++i) 
        if (isPrime[i] == 0) {
            for (int j = i * i; j <= 1000000; j += i) 
                isPrime[j] = 1;
        }
}

vector<int> primeList(int inputNums, int checkPrime[], int arr[]) {
    
    vector<int> ans = {};

    for (int i = 1; i <= inputNums; ++i) {
        if (!checkPrime[arr[i]])
            ans.push_back(arr[i]);
    }
    return ans;
}

int main() {

    int inputNums;

    cin >> inputNums;

    eratosthenes();

    for (int i = 1; i <= inputNums; ++i)
        cin >> arr[i];

    vector<int> ans = primeList(inputNums, isPrime, arr);
    
    int ansSize = ans.size();

    for (int i = 0; i < ansSize; ++i) 
        cout << ans[i] << " ";

    return 0;
}
