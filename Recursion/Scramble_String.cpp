#include <bits/stdc++.h>
using namespace std;

// Recursive helper function to check if s1 is a scramble of s2
bool isScramble(string s1, string s2, unordered_map<string, bool> &dp) {
    // If both strings are equal
    if (s1 == s2)
        return true;

    // If lengths differ
    if (s1.length() != s2.length())
        return false;

    // Create a key for memoization
    string key = s1 + "_" + s2;
    if (dp.find(key) != dp.end())
        return dp[key];

    int n = s1.length();

    // Optimization: if both strings don’t have same set of characters
    string temp1 = s1, temp2 = s2;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if (temp1 != temp2)
        return dp[key] = false;

    // Try every possible partition
    for (int i = 1; i < n; i++) {
        // Case 1: No swap
        bool case1 = isScramble(s1.substr(0, i), s2.substr(0, i), dp) &&
                     isScramble(s1.substr(i), s2.substr(i), dp);

        // Case 2: With swap
        bool case2 = isScramble(s1.substr(0, i), s2.substr(n - i), dp) &&
                     isScramble(s1.substr(i), s2.substr(0, n - i), dp);

        if (case1 || case2)
            return dp[key] = true;
    }

    return dp[key] = false;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    unordered_map<string, bool> dp;
    if (isScramble(s1, s2, dp))
        cout << "Yes, \"" << s2 << "\" is a scrambled string of \"" << s1 << "\".\n";
    else
        cout << "No, \"" << s2 << "\" is NOT a scrambled string of \"" << s1 << "\".\n";

    return 0;
}
