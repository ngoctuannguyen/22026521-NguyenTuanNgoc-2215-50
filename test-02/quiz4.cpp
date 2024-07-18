int GCD(int a, int b) {
    int temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b != 0) {
        int result = GCD(b, a % b);
        //cout << result << "\n";
        return result;
    }
    else return a;
} 

bool is_coprime(int a, int b) {
    if (GCD(a, b) == 1)
        return true;
    return false;
}