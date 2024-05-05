#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {-3, 5, 56, 34, 14, 64, 19};
    int maximum = arr[0];
    for (int i = 0; i < 7; i++)
    {
        maximum = max(arr[i], maximum);
        cout << maximum << ", ";
    }
    return 0;
}