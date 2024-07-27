// write a program to find the number which is persent only one time in the array and rest are persent twice

#include <iostream>
using namespace std;

int singleNumber(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[9] = {1, 5, 2, 3, 1, 4, 4, 2, 5};
    cout << "The number which is persent only one time is " << singleNumber(arr, size(arr)) << endl;
    return 0;
}