#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int i, int ors, int maxi, vector<int>& nums) {
        if(i >= nums.size()) {
            return (ors == maxi) ? 1 : 0;
        }

        int cnt = 0;
        cnt += solve(i + 1, ors | nums[i], maxi, nums);
        cnt += solve(i + 1, ors, maxi, nums);

        return cnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;

        for(auto it: nums) {
            maxi |= it;
        }

        return solve(0, 0, maxi, nums);
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solution.countMaxOrSubsets(nums);
    cout << "The number of subsets with the maximum OR value is: " << result << endl;

    return 0;
}
