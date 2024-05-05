#include<iostream>
#include<math.h>
using namespace std;

int main() {
     int a,remainder=0,b=0;
    cout<<"Enter the number:- ";
    cin>>a;
    int temp=a;
    while (a>0)
    {
        remainder=a%10;
        a/=10;
        // b+=remainder*remainder*remainder;
        b+=pow(remainder,3);
    }
    if (temp==b)
    {
        cout<<" yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}