#include <bits/stdc++.h>

using namespace std;

int longest_subarray(vector<int> &nums, int k)
{
    int longest = 0;

    int left = 0;

    int sum = 0;

    for(int right=0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }

        if(sum == k) longest = max(longest, right - left + 1);
    }

    return longest;
}

int longest_subarray_with_negatives(vector<int> &nums, int k)
{
    int longest = 0;

    unordered_map<int, int> sums;

    int sum = 0;

    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];

        if(sum == k) longest = i+1;

        int prefix = sum - k;

        if(sums.find(prefix) != sums.end())
        {
            longest = max(longest, i - sums[prefix]);
        }

        if(sums.find(sum) == sums.end())
        {
            sums[sum] = i;
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};

    cout << longest_subarray_with_negatives(arr, 0) << endl;

    return 0;
}
