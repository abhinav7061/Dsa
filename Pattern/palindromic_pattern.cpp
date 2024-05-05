#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a number:- ";
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            int number = (j <= i) ? (i - j + 1) : (j - i + 1);
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}