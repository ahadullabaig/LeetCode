#include <bits/stdc++.h>

using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int left = 0, right = 0;

    for(int x : weights)
    {
        left = max(left, x);
        right += x;
    }

    while(left < right)
    {
        int mid = (left + right) / 2;

        int d = 1, total = 0;

        for(int x : weights)
        {
            if((total + x) > mid)
            {
                total = 0;
                d++;
            }

            total += x;
        }

        if(d <= days) right = mid;

        else left = mid+1;
    }

    return right;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int days = 10;

    cout << shipWithinDays(weights, days) << endl;

    return 0;
}
