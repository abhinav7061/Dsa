#include <bits/stdc++.h>
using namespace std;

void sumOfTwoBinary(int a, int b)
{
    int x = 0;
    while (a > 0 || b > 0)
    {
        a /= 10;
        b /= 10;
        x++;
    }
    int sum[x + 1];
    // for (int i = 0; i <= x; i++)
    // {
    //     sum[i] = 0;
    // }
    int prevCarry = 0;
    for (int i = 0; i <= x; i++)
    {
        if ((a % 10 == 0) && (b % 10 == 0))
        {
            sum[i] = prevCarry;
            prevCarry = 0;
        }
        else if (((a % 10 == 1) && (b % 10 == 0)) || ((b % 10 == 1) && (a % 10 == 0)))
        {
            if (prevCarry == 1)
            {
                sum[i] = 0;
                prevCarry = 1;
            }
            else
            {
                sum[i] = 1;
                // prevCarry = 0;
            }
        }
        else
        {
            sum[i] = prevCarry;
            prevCarry = 1;
        }
        a /= 10;
        b /= 10;
    }
    for (int i = 0; i < x; i++)
    {
        cout << sum[i] << " ";
    }

    // int ans = 0;
    // if(prevCarry == 1){
    //     sum[x] = 1;
    // }
    // for (int i = x; i >= 0; i--)
    // {
    //     ans = ans * 10 + sum[i];
    // }
    // return ans;
}
int main()
{
    int a, b;
    cout << "Enter the numbers:- ";
    cin >> a >> b;
    cout << "The sum of " << a << " and " << b << " is ";
    sumOfTwoBinary(a, b);
    return 0;
}