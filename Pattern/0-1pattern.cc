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
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i+j)%2==0) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    
    return 0;
}