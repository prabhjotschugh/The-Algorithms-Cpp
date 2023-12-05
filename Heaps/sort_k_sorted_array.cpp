#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void kSortedArraySort(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i <= k; ++i) {
        minHeap.push(arr[i]);
    }

    int index = 0;

    for (int i = k + 1; i < arr.size(); ++i) {
        arr[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
    }

    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    printArray(arr);
    kSortedArraySort(arr, k);
    printArray(arr);

    return 0;
}
