#include <iostream>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int a, b, c;
    cout << "Enter the number" << endl;
    cin >> a;
    for (int i = 1; i <=3; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            // if (i % 2 == 0)
            // {
            //     if ((i+j)%2==0)
            //     {
            //         cout<<"* ";
            //     }
            //     else
            //     {
            //         cout<<"  ";
            //     }
            // }
            // else
            // {
            //     if ((i + j) % 4 == 0)
            //     {
            //         cout << "* ";
            //     }
            //     else
            //         cout << "  ";
                
            // }
            if ((i+j)%4==0 || (i==2&&j%4==0))
            {
                cout<<"* ";
            }
            else cout<<"  ";
            
        }
        cout<<endl;
    }
    return 0;
}