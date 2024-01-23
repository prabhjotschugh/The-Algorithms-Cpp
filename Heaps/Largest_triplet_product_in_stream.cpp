#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int largestTripletProduct(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
        cout << "Not enough elements in the stream." << endl;
        return -1;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    int tripletProduct = -1;

    for (int i = 0; i < n; ++i) {
        int currentNum = nums[i];

        maxHeap.push(currentNum);
        if (maxHeap.size() > 3) {
            maxHeap.pop();
        }

        minHeap.push(currentNum);
        if (minHeap.size() > 2) {
            minHeap.pop();
        }

        if (maxHeap.size() == 3) {
            int maxProduct = maxHeap.top() * maxHeap.top();
            maxHeap.pop();
            maxProduct *= maxHeap.top();
            tripletProduct = max(tripletProduct, maxProduct);
        }
    }

    return tripletProduct;
}

int main() {
    vector<int> nums = {1, 10, 2, 6, 5, 3};
    int result = largestTripletProduct(nums);
    cout << "Largest Triplet Product: " << result << endl;

    return 0;
}
