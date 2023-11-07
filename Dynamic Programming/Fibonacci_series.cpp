#include <iostream>
#include <vector>

std::vector<long long> memo;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    memo.resize(n + 1, -1);

    std::cout << "Fibonacci series up to " << n << " terms:\n";
    for (int i = 0; i <= n; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
￼Enter
