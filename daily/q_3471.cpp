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

int op_largestInteger(vector<int> &nums, int k) // O(n)
{
    int n = nums.size();

    int largest = INT_MIN;

    unordered_map<int, int> counts;

    for(int x : nums) counts[x]++;

    if(k > 1 && k < n)
    {
        if(counts[nums[0]] == 1 && counts[nums[n-1]] == 1) return max(nums[0], nums[n-1]);

        else if(counts[nums[0]] == 1) return nums[0];

        else if(counts[nums[n-1]] == 1) return nums[n-1];

        else return -1;
    }

    for(auto [num, count] : counts)
    {
        if(count == 1 || k == n)
        {
            largest = max(largest, num);
        }
    }

    return (largest != INT_MIN) ? largest : -1;
}

int main()
{
    vector<int> nums = {3, 9, 7, 10, 1, 7};

    int k = 4;

    cout << largestInteger(nums, k) << endl;

    cout << op_largestInteger(nums, k) << endl;

    return 0;
}
