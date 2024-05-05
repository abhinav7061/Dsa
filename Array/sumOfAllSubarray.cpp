#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {3, 5, 56, 34, 14, 26, 19};
    int sum_Of_All_SubArray = 0;
    for (int i = 0; i <= 7; i++)
    {
        int sum = 0;
        for (int j = i; j < 7; j++)
        {
            sum += arr[j];
            cout << sum << " ";
            sum_Of_All_SubArray += sum;
        }
    }
    cout << endl
         << sum_Of_All_SubArray << endl;
    return 0;
}