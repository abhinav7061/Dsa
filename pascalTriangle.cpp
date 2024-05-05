#include<iostream>
#include<math.h>
using namespace std;
int fact(int a){
    int factorial=1;
    for (int i = 2; i <=a; i++)
    {
        factorial*=i;
    }
    return factorial;
}
void pascal(int num){
    for (int i = 0; i <num; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            int element=fact(i)/(fact(i-j)*fact(j));
            cout<<element<<" ";
        }
        cout<<endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("pattern/input.txt","r",stdin);
      freopen("pattern/output.txt","w",stdout);
    #endif
     int a;
    // cout<<"Enter the interval\n";
    cin>>a;
    pascal(a);
    return 0;
}