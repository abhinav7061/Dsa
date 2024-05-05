#include<iostream>
#include<math.h>
using namespace std;
void fibonacy(int a){
    int nextTerm=0,t1=0,t2=1;
    for (int i = 2; i <=a; i++)
    {
        nextTerm=t1+t2;
        cout<<t1<<", ";
        t1=t2;
        t2=nextTerm;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("pattern/input.txt","r",stdin);
      freopen("pattern/output.txt","w",stdout);
    #endif
     int a,b,c;
    // cout<<"Enter the interval\n";
    cin>>a;
    fibonacy(a);
    return 0;
}