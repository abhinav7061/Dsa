#include <iostream>
using namespace std;

int main()
{
    int row, b, c;
    cout << "Enter the number";
    cin >> row;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c = j<2? i : c+row-j+1;
            
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}