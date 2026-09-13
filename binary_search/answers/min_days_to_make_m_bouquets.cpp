#include <bits/stdc++.h>

using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    long long required_flowers = 1LL * m * k;

    if(n < required_flowers) return -1;

    int left = 1, right = 1;

    for(int x : bloomDay) right = max(right, x);

    while(left < right)
    {
        int mid = (left + right) / 2;

        int bouquets = 0, flowers = 0;

        for(int i=0; i<n; i++)
        {
            // adjacency check
            if(bloomDay[i] > mid) flowers = 0;

            else flowers++;

            if(flowers == k)
            {
                bouquets++;
                flowers = 0;
            }

            if(bouquets == m) break;
        }

        if(flowers == k) bouquets++;

        if(bouquets == m) right = mid;

        else left = mid+1;
    }

    return right;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};

    int m = 3, k = 1;

    cout << minDays(bloomDay, m, k) << endl;

    return 0;
}
