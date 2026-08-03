#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0, max_sum = INT_MIN;

    for(int x : nums)
    {
        sum += x;

        max_sum = max(sum, max_sum);

        if(sum < 0) sum = 0;
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums) << endl;

    return 0;
}
