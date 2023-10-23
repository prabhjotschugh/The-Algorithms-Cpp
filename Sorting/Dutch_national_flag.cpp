// sort array of 0s, 1s and 2s
#include <bits/stdc++.h>
using namespace std;
void sort012(int a[], int arr_size)
{
    int low = 0;
    int high = arr_size - 1;
    int mid = 0;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low++], a[mid++]);
        }

        else if (a[mid] == 1)
        {
            mid++;
        }

        else
        {
            swap(a[mid], a[high--]);
        }
    }
}

void printArray(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    printArray(arr, n);

    return 0;
}
