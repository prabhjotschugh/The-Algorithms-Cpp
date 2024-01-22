#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    if (envelopes.empty()) return 0;

    sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
        return a.first == b.first ? b.second < a.second : a.first < b.first;
    });

    int n = envelopes.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i].second > envelopes[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<pair<int, int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of envelopes that can be nested: " << maxEnvelopes(envelopes) << endl;

    return 0;
}
￼Enter
