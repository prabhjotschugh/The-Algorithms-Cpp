#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int shortestCommonSupersequence(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = i + j;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

string constructSCS(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = i + j;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = m, j = n;
    string result;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result = str1[i - 1] + result;
            i--;
            j--;
        } else {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                result = str1[i - 1] + result;
                i--;
            } else {
                result = str2[j - 1] + result;
                j--;
            }
        }
    }

    while (i > 0) {
        result = str1[i - 1] + result;
        i--;
    }
    while (j > 0) {
        result = str2[j - 1] + result;
        j--;
    }
    return result;
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    int scsLength = shortestCommonSupersequence(str1, str2);
    string scs = constructSCS(str1, str2);
    cout << "Shortest Common Supersequence Length: " << scsLength << endl;
    cout << "Shortest Common Supersequence: " << scs << endl;
    return 0;
}
