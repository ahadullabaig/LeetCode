#include <bits/stdc++.h>

using namespace std;

int subarraysXOR_k(vector<int> &nums, int k) // O(n*n)
{
    int count = 0;

    int n = nums.size();

    for(int i=0; i<n; i++)
    {
        int num = nums[i];

        if(num == k) count++;

        for(int j = i+1; j<n; j++)
        {
            num ^= nums[j];

            if(num == k) count++;
        }
    }

    return count;
}

long long beautifulSubarrays(vector<int> &nums) // O(n)
{
    long long count = 0;

    unordered_map<int, int> xors;

    xors[0] = 1;

    int num = 0;

    int n = nums.size();

    for(int i=0; i<n; i++)
    {
        num ^= nums[i];

        if(xors.contains(num)) count += xors[num];

        xors[num]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {4, 3, 1, 2, 4};

    int k = 0;

    cout << subarraysXOR_k(nums, k) << endl;

    cout << beautifulSubarrays(nums) << endl; // Q2588

    return 0;
}
