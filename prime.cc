#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int a){
    for (int i = 2; i <=sqrt(a); i++)
    {
        if (a%i==0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("pattern/input.txt","r",stdin);
      freopen("pattern/output.txt","w",stdout);
    #endif
     int a,b,c;
    // cout<<"Enter the interval\n";
    cin>>a>>b;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            cout<<i<<", ";
        }
        
    }
    
    return 0;
}