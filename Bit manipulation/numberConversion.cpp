#include <iostream>
using namespace std;
int binaryToDecimal(int n)
{
    int ans = 0, x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 2;
        n /= 10;
    }
    return ans;
}
int octalToDecimal(int n)
{
    int ans = 0, x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 8;
        n /= 10;
    }
    return ans;
}
int HexadecimalToDecimal(string n)
{
    int ans = 0, x = 1, s = n.size();
    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x * (n[i] - '0');
            x *= 16;
        }
        else
        {
            ans += x * (n[i] - 'A' + 10);
            x *= 16;
        }
    }
    return ans;
}
int decimalToBinary(int n)
{
    int ans = 0, x = 1;
    // the following gives the reverse of the desired binary representation we can reverse it to get the correct result
    // while (n > 0)
    // {
    //     int y = n % 2;
    //     ans = ans * 10 +y;
    //     n /= 2;
    // }
    while (n >=x){
        x*=2;
    }
    x/=2;
    while (x>0)
    {
        int lastdigit = n/x;
        n -= lastdigit*x;
        ans = ans * 10 + lastdigit;
        x/=2;
    }
    return ans;
}
int decimalToOctal(int n){
    int ans = 0, x = 1;
    while(n >=x)
        x*=8;
    x/=8;
    while (n > 0)
    {
        int lastdigit = n/x;
        ans = ans * 10 + lastdigit;
        n-= lastdigit*x;
        x /= 8;
    }
    return ans;
}
string decimalToHexadecimal(int n){
    string ans = "";
    int x = 1;
    while(n >=x)
        x*=16;
    x/=16;
    while (n > 0)
    {
        int lastdigit = n/x;
        n-= lastdigit*x;
        if (lastdigit<=9){
            ans += to_string(lastdigit);
        }
        else{
            char c = 'A' + lastdigit-10;
            ans.push_back(c); 
        }
        x /= 16;
    }
    return ans;
}
int main()
{
    int a;
    // string a;
    cout << "Enter the number:- ";
    cin >> a;
    // cout << decimalToOctal(a) << endl;
    cout << octalToDecimal(a) << endl;
    return 0;
}