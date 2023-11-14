#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int dp[201][201];

int solve(int e, int f) {
    if (f == 0 || f == 1) {
        return f;
    }

    if (e == 1) {
        return f;
    }

    if (dp[e][f] != -1) {
        return dp[e][f];
    }

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++) {
        int first = (dp[e - 1][k - 1] != -1) ? dp[e - 1][k - 1] : solve(e - 1, k - 1);

        int second = (dp[e][f - k] != -1) ? dp[e][f - k] : solve(e, f - k);

        int ans = 1 + max(first, second);

        mini = min(mini, ans);
    }

    return dp[e][f] = mini;
}

int eggDrop(int e, int f) {
    memset(dp, -1, sizeof(dp));
    return solve(e, f);
}

int main() {
    int eggs = 2;
    int floors = 10;

    int minAttempts = eggDrop(eggs, floors);

    cout << "Minimum attempts needed: " << minAttempts << endl;

    return 0;
}
