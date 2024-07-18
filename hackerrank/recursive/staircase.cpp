#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stepPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

const long long MOD = 10000000007;

int memo[40];

long long stepPerms(long long n) {
    
    if (n < 0) {
        memo[n] = 0;
        return memo[n];
    }
    if (n == 0 || n == 1) {
        memo[n] = 1;
        return memo[n];
    }
    if (n == 2) {
        memo[n] = 2;
        return memo[n]; 
    }
    // if (n == 3) {
    //     memo[n] = 4;
    //     return memo[n];
    // }
    
    if (memo[n] != -1) {
        return ;
    }
    memo[n - 1] = stepPerms(n - 1);
    memo[n - 2] = stepPerms(n - 2);
    memo[n - 3] = stepPerms(n - 3);
    
    return (memo[n - 1] + memo[n - 2] + memo[n - 3]) % MOD;
}

// int stepPerms(int n) {
//     static vector<int> present = {1,1,2};
//     if(n < present.size())
//         return present[n];
//     else if(n-1 < present.size())
//         present.push_back(present[n-1] + present[n-2] + present[n-3]);
//     else
//         present.push_back(stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3));
//     return present[n];
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));
    
    memset(memo, -1, 40);

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));
        
        n = (long long) n; 

        long long res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
