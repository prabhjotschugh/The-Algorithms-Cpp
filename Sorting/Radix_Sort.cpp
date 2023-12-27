#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
￼Enter
