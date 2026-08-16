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

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};

    int k = 6;

    cout << subarraysXOR_k(nums, k) << endl;

    return 0;
}
