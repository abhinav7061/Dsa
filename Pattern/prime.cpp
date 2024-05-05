// #include<iostream>
// using namespace std;

// int main() {
//      int a,b;
//     cout<<"Enter the number";
//     cin>>a;
//     b=2;
//     while(b<a){
//         int div=2;
//         while(div<b){
//             if(b%div==0){
//                 b++;
//                 break;
//             }
//             else{
//                 div++;
//             }
//         }
//         cout<<b<<",";
//         b++;
//     }
//     return 0;
// }
#include<iostream>
using namespace std;

int main() {
     int a;
    cout<<"Enter the number";
    cin>>a;
    for(int c=2;c<a;c++){
        for (int i = 2; i < c; i++)
        {
            if(c%i==0){
                c++;
                // i=2;
                // break;
            }
        }
        cout<<c<<",";
    }
    return 0;
}