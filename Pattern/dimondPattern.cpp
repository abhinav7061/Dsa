#include <iostream>
using namespace std;
int main()
{
    int row;
    cout << "Enter the number of row" << endl;
    cin >> row;
    for (int i = 1; i < 2 * row; i++)
    {
        for (int j = 1; j <= ((i <= row) ? row - i : i - row); j++)
            cout << "  ";
        for (int j = 1; j <= ((i <= row) ? 2 * i : 2 * (2 * row - i)) - 1; j++)
            cout << "* ";
        cout << endl;
    }

    return 0;
}
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif++