#include <bits/stdc++.h>

using namespace std;

int reversePairs(vector<int> &nums)
{
    int n = nums.size();

    int count = 0;

    for(int i=0; i < n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            long long j_2 = 1LL * nums[j] * 2;

            if(nums[i] > j_2) count++;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {2, 4, 3, 5, 1};

    cout << reversePairs(nums) << endl;

    return 0;
}
