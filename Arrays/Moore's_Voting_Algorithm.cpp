#include <iostream>
#include <vector>

using namespace std;

// Function to find the majority element
int findMajorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

    // Step 1: Find the candidate for the majority element
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Step 2: Verify if the candidate is the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 2, 2, 2}; // Example array
    int result = findMajorityElement(nums);

    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "There is no majority element." << endl;
    }

    return 0;
}
