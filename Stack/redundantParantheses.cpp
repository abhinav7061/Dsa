// write a program to check whether a redundant paranthese is present in the given expression

#include <iostream>
#include <stack>
using namespace std;

bool isRedundant(string &exp)
{
    stack<char> st;
    for (size_t i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (st.top() == '(')
            {
                return true;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string exp = "((a+b)*(c-d))";

    if (!isRedundant(exp))
        cout << "The expression has no redundant parentheses." << endl;
    else
        cout << "The expression has redundant parentheses." << endl;
    return 0;
}
