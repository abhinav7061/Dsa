#include<iostream>
using namespace std;

int main() {
     int a,b,c;
    cout<<"Enter the number";
    cin>>a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <=a; j++)
        {
            if (j<=a-i)
            {
                cout<<" ";
            }
            else cout<<"*";
            
        }
    // Below is also right for desired result
    //     for (int j = 1; j<= a-i; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("*");
    //     }
        
        cout<<endl;
    }
    
    return 0;
}