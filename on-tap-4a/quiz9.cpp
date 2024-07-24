#include <bits/stdc++.h>

std::string decimal_to_binary(long number)
{
    // Your code here
    std::string binaryResult = "";
    if (number == 0) {
        return "0";
    }
    while (number) {
        binaryResult = char(int(number % 2) + '0') + binaryResult;
        number /= 2;
    }
    return binaryResult;
}