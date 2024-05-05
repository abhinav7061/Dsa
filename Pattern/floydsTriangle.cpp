#include <iostream>
using namespace std;
 
int main() {
    int a,count=1;
    cout << "Enter the number of rows:- ";
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= i; j++){
            cout <<count<<" ";
            count++;
        }
        cout << endl;
    }
    
    return 0;
}