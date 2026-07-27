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

int main()
{
    vector<int> arr = {5, 2, 3, 1};

    cout << longest_subarray(arr, 5) << endl;

    return 0;
}
