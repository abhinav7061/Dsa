#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int res = 0;
    while (x)
    {
        res = (res * 10) + (x % 10);
        x /= 10;
    }
    return res;
}
int addTwoBinary(int x, int y)
{
    int sum = 0;
    int prevCarry = 0;
    while (x > 0 || y > 0)
    {
        if (x % 2 == 0 && y % 2 == 0)
        {
            sum = sum * 10 + prevCarry;
            prevCarry = 0;
        }
        else if ((x % 2 == 1 && y % 2 == 0) || (y % 2 == 1 && x % 2 == 0))
        {
            if (prevCarry == 1)
            {
                sum = sum * 10+0;
                prevCarry = 1;
            }
            else
            {
                sum = sum * 10 + 1;
                prevCarry = 0;
            }
        }
        else
        {
            sum = sum * 10 + prevCarry;
            prevCarry = 1;
        }
        x /= 10;
        y /= 10;
    }
    if(prevCarry==1){
        sum = sum * 10 + 1;
    }
    // while (x > 0)
    // {
    //     if (prevCarry == 1)
    //     {
    //         if (x % 2 == 1)
    //         {
    //             sum = sum * 10;
    //             prevCarry = 1;
    //         }

    //         else
    //         {
    //             sum = sum * 10 + 1;
    //             prevCarry = 0;
    //         }
    //     }
    //     else
    //     {
    //         sum = sum * 10 + (x % 2);
    //     }
    //     x /= 10;
    // }
    // while (y > 0)
    // {
    //     if (prevCarry == 1)
    //     {
    //         if (y % 2 == 1)
    //         {
    //             sum = sum * 10;
    //             prevCarry = 1;
    //         }

    //         else
    //         {
    //             sum = sum * 10 + 1;
    //             prevCarry = 0;
    //         }
    //     }
    //     else
    //     {
    //         sum = sum * 10 + (y % 2);
    //     }
    //     y /= 10;
    // }
    return sum;
    // return reverse(sum);
}
int main()
{
    int a, b;
    cout << "Enter the numbers:- ";
    cin >> a >> b;
    cout << addTwoBinary(a, b) << endl;
    return 0;
}