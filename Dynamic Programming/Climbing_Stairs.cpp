#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n <= 1) {
        return 1;
    }
    
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    
    int ways = climbStairs(n);
    cout << "Number of distinct ways to climb " << n << " stairs: " << ways << std::endl;
    
    return 0;
}
