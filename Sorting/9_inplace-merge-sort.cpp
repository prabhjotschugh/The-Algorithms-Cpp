//In-Place Merge Sort --> TC: O(n^2), SC: O(1)
/*
Unlike the standard merge sort, which uses O(n) additional space, the in-place version reduces the auxiliary space complexity to O(1) for the merging process, making it more memory-efficient.
It retains the advantages of the divide-and-conquer strategy, making it efficient for large datasets with a time complexity of O(n log n) in all cases (best, average, and worst).
In-place merge sort can be beneficial for large datasets where memory usage is a concern, particularly when dealing with large arrays in environments with limited memory.
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int start2 = mid + 1;

    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2]) return;

    // Two pointers to maintain start of both subarrays
    while (left <= mid && start2 <= right) {
        if (arr[left] <= arr[start2]) {
            left++;
        } else {
            int value = arr[start2];
            int index = start2;

            // Shift all elements between left and start2 right by 1
            while (index != left) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[left] = value;

            // Update all pointers
            left++;
            mid++;
            start2++;
        }
    }
}

void inPlaceMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        inPlaceMergeSort(arr, left, mid);
        inPlaceMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    inPlaceMergeSort(arr, 0, n - 1);
    
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
