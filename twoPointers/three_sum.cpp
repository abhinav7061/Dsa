// given an array and a value, find if htere exists three numbers whose sum is equal to the given value
// return true or false accordingly.

#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(vector<int> arr, int x)
{
    sort(arr.begin(), arr.end()); // sorting the array in ascending order
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == x)
            {
                // cout << "Index of the triplet are: " << i << ", " << l << ", " << r << endl;
                cout << "Triplet found: " << arr[i] << ", " << arr[l] << ", " << arr[r] << endl;
                return true;
            }

            else if (arr[i] + arr[l] + arr[r] < x)
            {
                l++;
            }

            else
            {
                r--;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {5, 98, 34, 17, 3};
    int target = 118;
    if (find3Numbers(nums, target))
        cout << "There are 3 numbers in the array whose sum is " << target << endl;
    else
        cout << "No such triplet found in the array." << endl;

    return 0;
}
