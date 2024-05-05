#include<iostream>
using namespace std;

int main() {
     int a,remainder=0,b=0;
    cout<<"Enter the number:- ";
    cin>>a;
    while (a>0)
    {
        remainder=a%10;
        a/=10;
        b=b*10+remainder;
    }
    cout<<"reversed number is:- "<<b<<endl;
    return 0;
}