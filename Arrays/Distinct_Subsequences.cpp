#include <iostream>
#include <unordered_set>

// Function to count distinct subsequences
int countDistinctSubsequences(const std::string& str) {
    const int MOD = 1e9 + 7;
    int n = str.length();

    // dp array to store the count of distinct subsequences
    std::vector<int> dp(n + 1, 0);

    // Initialize the array for an empty string
    dp[0] = 1;

    // Map to store the last index of each character
    std::unordered_map<char, int> lastOccurrence;

    for (int i = 1; i <= n; ++i) {
        dp[i] = (2 * dp[i - 1]) % MOD;

        // If the current character has occurred before
        if (lastOccurrence.find(str[i - 1]) != lastOccurrence.end()) {
            // Subtract the count of subsequences ending with the previous occurrence
            dp[i] = (dp[i] - dp[lastOccurrence[str[i - 1]] - 1] + MOD) % MOD;
        }

        // Update the last occurrence index of the current character
        lastOccurrence[str[i - 1]] = i;
    }

    return dp[n];
}

int main() {
    std::string str = "abcabc";
    std::cout << "Number of distinct subsequences: " << countDistinctSubsequences(str) << std::endl;

    return 0;
}
