#include <iostream>
#include<climits>
#include <vector>

using namespace std;
int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int chainLength = 2; chainLength <= n; chainLength++) {
        for (int i = 0; i < n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> dimensions = {10, 30, 5, 60};
    int minMultiplications = matrixChainMultiplication(dimensions);

    cout << "Minimum number of scalar multiplications: " << minMultiplications << endl;

    return 0;
}
