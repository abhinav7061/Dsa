#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {10, 7, 4, 5, 8, 10, 11}, maxLength = 2, currentLength = 2;
    int prevDiff = arr[1] - arr[0];
    for (int i = 2; i < 7; i++)
    {
        if (prevDiff == arr[i] - arr[i - 1])
            currentLength++;
        else
        {
            prevDiff = arr[i] - arr[i - 1];
            currentLength = 2;
        }
        maxLength = max(maxLength, currentLength);
    }
    cout << maxLength << endl;
    return 0;
}