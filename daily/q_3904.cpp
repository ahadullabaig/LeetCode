#include <bits/stdc++.h>

using namespace std;

int firstStableIndex(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> minimums;

    int minimum = INT_MAX;

    for(int i = n-1; i >= 0; i--)
    {
        if(nums[i] < minimum)
        {
            minimums[i] = nums[i];
            minimum = nums[i];
        }

        else minimums[i] = minimum;
    }

    int maximum = nums[0];

    for(int i=0; i<n; i++)
    {
        maximum = max(maximum, nums[i]);

        int diff = maximum - minimums[i];

        if(diff <= k) return i;
    }

    return -1;
}

int main()
{
    vector<int> nums = {6, 1, 4};

    int k = 5;

    cout << firstStableIndex(nums, k) << endl;

    return 0;
}
