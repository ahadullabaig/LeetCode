#include <bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = 1;

    for(int x : piles) right = max(right, x);

    int k = INT_MAX;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        int hours = h;

        for(int x : piles)
        {
            if(x%mid == 0)
            {
                hours -= x/mid;
            }
            else
            {
                hours -= (x/mid) + 1;
            }

            if(hours > h) break;
        }

        if(hours >= 0)
        {
            k = min(k, mid);
            right = mid-1;
        }

        else left = mid+1;
    }

    return k;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};

    int h = 8;

    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}
