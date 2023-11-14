#include <iostream>
#include <vector>

using namespace std;
int subsetSum(vector<int>& arr, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int findTargetSumWays(vector<int>& arr, int target) {
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if ((sum + target) % 2 != 0) {
        return 0;
    }
    int targetSum = (sum + target) / 2;
    return subsetSum(arr, n, targetSum);
}

int main() {
    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 3;

    int ways = findTargetSumWays(arr, target);

    cout << "Number of ways to achieve the target sum: " << ways << endl;

    return 0;
}
