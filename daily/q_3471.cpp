#include <bits/stdc++.h>

using namespace std;

int largestInteger(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> counts;

    int right = k;

    while(right <= n)
    {
        int left = right - k;

        unordered_set<int> seen;

        while(left < right)
        {
            seen.insert(nums[left]);

            left++;
        }

        for(int x : seen) counts[x]++;

        right++;
    }

    int largest = INT_MIN;

    for(auto [num, count] : counts)
    {
        if(count == 1)
        {
            largest = max(largest, num);
        }
    }

    return (largest != INT_MIN) ? largest : -1;
}

int main()
{
    vector<int> nums = {3, 9, 7, 2, 1, 7};

    int k = 4;

    cout << largestInteger(nums, k) << endl;

    return 0;
}
