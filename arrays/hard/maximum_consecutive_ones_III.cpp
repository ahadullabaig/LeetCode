#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int longest = INT_MIN;

    int n = nums.size();

    int left = 0, right = 0;

    int zeroes = 0;

    while(right < n)
    {
        if(nums[right] == 0) zeroes++;

        if(zeroes > k)
        {
            longest = max(longest, right - left);

            while(zeroes > k && left <= right)
            {
                if(nums[left] == 0) zeroes--;

                left++;
            }
        }

        right++;
    }

    if(zeroes == k) longest = max(longest, right - left);

    return (longest == INT_MIN) ? n : longest;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

    int k = 3;

    cout << longestOnes(nums, k) << endl;

    return 0;
}
