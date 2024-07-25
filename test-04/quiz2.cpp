#include <bits/stdc++.h>

using namespace std;

class BigInt 
{
    string value;
public:
    // Hàm khởi tạo số nguyên lớn bằng 0
    BigInt();

    // Hàm khởi tạo số nguyên lớn từ một xâu c-string
    BigInt(const char*);

    // Hàm khởi tạo số nguyên lớn từ một số nguyên lớn khác
    BigInt(const BigInt& );

    // Toán tử in ra màn hình
    friend ostream& operator<< (ostream& , const BigInt& );

    // Toán tử cộng
    friend BigInt operator+(const BigInt& , const BigInt & );
};

// Toán tử in ra màn hình
ostream& operator<<(ostream& os, const BigInt& num)
{
    cout << num.value;
    return os;
}

// Hàm khởi tạo
BigInt::BigInt() 
{  
    value = "0";
}

BigInt::BigInt(const char *num)
{
    // string s(num)
    // value = s;
    value = num;
}

BigInt::BigInt(const BigInt& num)
{
    value = num.value;
}

// Toán tử cộng
BigInt operator+(const BigInt& num, const BigInt& other)
{   
    string str1 = num.value;
    string str2 = other.value;
    int len1 = str1.length();
    int len2 = str2.length();

    string strResult = "";

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            str2 = "0" + str2;
        }
    }
    else {
        for (int i = 0; i < len2 - len1; i++) {
            str1 = "0" + str1;
        }
    }

    int carry = 0;

    for (int i = str1.length() - 1; i >= 0; i--) {
        int sum = int(str1[i] - '0') + int(str2[i] - '0') + carry;
        strResult = char((sum % 10) + '0') + strResult;
        carry = sum / 10;
    }

    if (carry > 0) {
        strResult = char(carry + '0') + strResult;
    }

    char* number = new char[strResult.length() + 1];
    strcpy(number, strResult.c_str());

    return BigInt(num);
}   

int main() {

    BigInt a("99"), b("1");
    BigInt c = a + b;
    cout << c << endl;
    cout << (c + a) << endl;
    cout << (c + b) << endl;

    return 0;
}