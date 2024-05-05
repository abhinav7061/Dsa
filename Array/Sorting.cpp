#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                swap(arr[j], arr[i]);
        }
    }
    print(arr, n);
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (temp < arr[j] && j > 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = temp;
    }
    print(arr, n);
}

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    print(arr, n);
}

int main()
{
    int arr[7] = {3, 5, 56, 34, 14, 26, 19};
    // selectionSort(arr, 7);
    // insertionSort(arr, 7);
    bubbleSort(arr, 7);
    return 0;
}