#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int count = 0;

    unordered_map<int, int> prefixes;

    prefixes[0] = 1;

    int sum = 0;

    for(int x : nums)
    {
        sum += x;

        int required_sum = sum - k;

        count += prefixes[required_sum];

        prefixes[sum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 1, -1, 2, 3, -2, 1, 1, 2};

    int k = 3;

    cout << subarraySum(nums, k) << endl;
    
    return 0;
}
