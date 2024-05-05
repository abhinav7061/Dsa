#include <iostream>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);
    // #endif
    int a, b, c;
    cout << "Enter the number" << endl;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= 2 * a; j++)
        {
            if (j <= i || j > 2 * a - i)
            {
                printf("* ");
            }
            else
                printf("  ");
        }
        cout << endl;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= 2 * a; j++)
        {
            if (j <= a - i + 1 || j > a + i - 1)
            {
                printf("* ");
            }
            else
                printf("  ");
        }
        cout << endl;
    }

    return 0;
}