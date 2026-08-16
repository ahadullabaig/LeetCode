#include <bits/stdc++.h>

using namespace std;

int longestSubarray(vector<int> &nums)
{
    int longest = 0;

    unordered_map<int, int> sums;

    sums[0] = -1;

    int sum = 0;

    int n = nums.size();

    for(int i=0; i<n; i++)
    {
        sum += nums[i];

        if(sums.contains(sum))
        {
            longest = max(longest, i - sums[sum]);
            continue;
        }

        sums[sum] = i;
    }

    return longest;
}

int main()
{
    vector<int> nums = {9, -3, 3, -1, 6, -5};

    cout << longestSubarray(nums) << endl;

    return 0;
}
