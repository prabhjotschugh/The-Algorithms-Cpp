#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    for (int num : nums) {
        maxHeap.push(num);

        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    vector<int> nums = {3, 1, 4, 2, 7, 5, 6};
    int k = 3;
    int result = kthSmallest(nums, k);
    cout << result << endl;
    return 0;
}