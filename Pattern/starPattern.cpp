#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);
    // #endif
     int a,b,c;
    cout<<"Enter the number:- ";
    cin>>a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = a-i; j >0; j--)
        {
            cout<<" ";
        }
        for (int j = 0; j < i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j =1; j<=i; j++)
        {
            cout<<" ";
        }
        for (int j = a-i; j>0; j--)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
