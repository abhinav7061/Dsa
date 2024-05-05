#include<iostream>
using namespace std;

int main() {
     int a,b,c;
    cout<<"Enter the number";
    cin>>a;
    for (int i = a; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }
    
    return 0;
}