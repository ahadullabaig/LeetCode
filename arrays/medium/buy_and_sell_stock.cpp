#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;

    int n = prices.size();

    int smallest = prices[0];

    for(int i=1; i<n; i++)
    {
        profit = max(profit, (prices[i] - smallest));

        smallest = min(smallest, prices[i]);
    }

    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}
