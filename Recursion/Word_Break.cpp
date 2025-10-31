#include <bits/stdc++.h>
using namespace std;

// Recursive helper function with memoization
bool solve(string s, unordered_set<string> &dict, int start, vector<int> &dp) {
    // If we reached the end, successful segmentation
    if (start == s.length())
        return true;

    // If already computed
    if (dp[start] != -1)
        return dp[start];

    string current = "";
    for (int end = start; end < s.length(); end++) {
        current += s[end];
        // If current prefix is in dictionary and rest can be broken
        if (dict.find(current) != dict.end() && solve(s, dict, end + 1, dp))
            return dp[start] = true;
    }

    return dp[start] = false;
}

bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(s.length(), -1);
    return solve(s, dict, 0, dp);
}

int main() {
    string s;
    int n;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter number of words in dictionary: ";
    cin >> n;

    vector<string> wordDict(n);
    cout << "Enter dictionary words:\n";
    for (int i = 0; i < n; i++)
        cin >> wordDict[i];

    if (wordBreak(s, wordDict))
        cout << "✅ Yes, the string can be segmented into dictionary words.\n";
    else
        cout << "❌ No, the string cannot be segmented into dictionary words.\n";

    return 0;
}
