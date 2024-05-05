#include<iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
     int a,b,c;
    cout<<"Enter the number"<<endl;
    cin>>a;
    for (int i = a; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}   