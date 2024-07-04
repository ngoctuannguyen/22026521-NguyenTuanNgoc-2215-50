#include <bits/stdc++.h>

using namespace std;

string U_20[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                     "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                     "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string thousands[] = {"", "thousand", "million"};

class NumToWords {

public:

    NumToWords() {}
        
    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return U_20[num] + " ";
        else if (num < 100)
            return tens[num / 10] + "-" + helper(num % 10);
        else
            return U_20[num / 100] + " hundred " + helper(num % 100);
    }

    string numToWords(int num) {

        num = abs(num);
        if (num == 0)
            return "zero";

        string result;

        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }

        while (result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};

int main() {
    int num;
    
    cin >> num;

    if (num < 0) {
        cout << "negative ";
    }
    
    NumToWords num_to_words;

    cout << num_to_words.numToWords(num) << endl;

    return 0;
}
