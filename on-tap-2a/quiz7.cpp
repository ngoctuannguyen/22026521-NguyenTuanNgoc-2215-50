#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    int min_a = 1000000;
    int min_b = 1000000;

    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        min_a = std::min(min_a, a);
        min_b = std::min(min_b, b);
    }

    std::cout << min_a * min_b << std::endl;

    return 0;
}
