#include <iostream>
#include <vector>
using namespace std;

bool isMatch(const string &s, const string &p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s, p;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;
    if (isMatch(s, p)) {
        cout << "The pattern matches the string." << endl;
    } else {
        cout << "The pattern does not match the string." << endl;
    }
    return 0;
}
