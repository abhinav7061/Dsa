// the span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the price of the stock was less than or equal to today's price. find the span of the stocks for all the days.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> price)
{
    stack<pair<int, int>> stack;
    vector<int> result(price.size(), 1);

    for (int i = 0; i < price.size(); ++i)
    {
        int span = 1; // Initialize the span value of current element with one
        while (!stack.empty() && price[i] > stack.top().first)
            span += stack.top().second, stack.pop();
        result[i] = span;
        stack.emplace(price[i], span);
    }
    return result;
}

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stockSpan(price);
    for (auto sp : span)
    {
        cout << sp << endl;
    }
    return 0;
}