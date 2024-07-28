#include <iostream>
using namespace std;

int catalan(int i)
{
    if (i <= 1)
        return 1;

    int res = 0;
    for (int j = 0; j < i; j++)
    {
        res += catalan(j) * catalan(i - 1 - j);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the number ";
    cin >> n;
    for (size_t i = 0; i <= n; i++)
    {
        cout << catalan(i) << " ";
    }

    return 0;
}