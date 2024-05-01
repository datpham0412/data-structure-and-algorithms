// Time : - Best: O(n) - When the array is already sorted
//        - Average - Worst: O(n^2)
// Space: O(1)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], size_t size)
{
    int i, j;
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void printArray(int arr[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "\n Sorted Array: ";
    printArray(arr, size);
    return 0;
}