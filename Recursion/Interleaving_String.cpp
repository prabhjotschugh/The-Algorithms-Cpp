#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp) {
    // Base case: if all strings are completely traversed
    if (k == s3.length()) {
        return (i == s1.length() && j == s2.length());
    }

    // If already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    bool first = false, second = false;

    // If next char of s1 matches with s3
    if (i < s1.length() && s1[i] == s3[k])
        first = solve(s1, s2, s3, i + 1, j, k + 1, dp);

    // If next char of s2 matches with s3
    if (j < s2.length() && s2[j] == s3[k])
        second = solve(s1, s2, s3, i, j + 1, k + 1, dp);

    return dp[i][j] = (first || second);
}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length())
        return false;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return solve(s1, s2, s3, 0, 0, 0, dp);
}

int main() {
    string s1, s2, s3;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;
    cout << "Enter string s3: ";
    cin >> s3;

    if (isInterleave(s1, s2, s3))
        cout << "✅ Yes, \"" << s3 << "\" is an interleaving of \"" << s1 << "\" and \"" << s2 << "\".\n";
    else
        cout << "❌ No, \"" << s3 << "\" is NOT an interleaving of \"" << s1 << "\" and \"" << s2 << "\".\n";

    return 0;
}
