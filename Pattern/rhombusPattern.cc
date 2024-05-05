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
        for (int j = a-i; j >0; j--)
        {
            cout<<" ";
        }
        for (int j = 0; j < a; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}