#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                swap(arr[j], arr[i]);
        }
    }
}

int binarySearch(int arr[], int n, int search)
{
    sort(arr, n);
    int start = 0, end = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == search)
            return mid;
        else if (arr[mid] < search)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int linearSearch(int arr[], int n, int search)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == search)
            return i;
    return -1;
}

int main()
{
    int arr[7] = {3, 5, 56, 34, 14, 26, 19};
    // int arr[7] = {3, 5, 25, 34, 37, 67, 98};
    int search;
    cout << "Enter the number which will be searched:- ";
    cin >> search;
    // int index = linearSearch(arr, 7, search);
    int index = binarySearch(arr, 7, search);
    if (index >= 0)
        cout << search << " found at index in sorted array in case of binary search: " << index << endl;
    else
        cout << search << " not found in array\n";

    return 0;
}