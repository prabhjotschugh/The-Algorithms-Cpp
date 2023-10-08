#include <bits/stdc++.h>
using namespace std;

int lis(int a[], int n) {
    vector<int> t;
    t.push_back(a[0]);

    int length = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] > t.back()) {
            t.push_back(a[i]);
            length++;
        } else {
            int index = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
            t[index] = a[i];
        }
    }

    return length;
}

int main() {
    int arr[] = {10, 0, 1, 5, 2, 7, 221, 118};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is " << lis(arr, n);

    return 0;
}
