#include <iostream>
using namespace std;

int Lsearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() 
{
    int arr[] = {10, 25, 5, 15, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = Lsearch(arr, size, target);

    if (result != -1) {
        cout << "Target " << target << " found at index --> " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }
}
