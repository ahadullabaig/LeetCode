#include <bits/stdc++.h>

using namespace std;

vector<int> maxSubArray(vector<int> &nums)
{
    int n = nums.size();

    int start = 0, end = 0;

    int sum = 0, max_sum = INT_MIN;

    int i = 0;

    for(int j=0; j<n; j++)
    {
        sum += nums[j];

        if(sum > max_sum)
        {
            max_sum = sum;
            start = i;
            end = j;
        }

        if(sum < 0)
        {
            sum = 0;
            i = j+1;
        }
    }

    return {start, end};
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    vector<int> indices = maxSubArray(nums);

    for(int i = indices[0]; i <= indices[1]; i++) cout << nums[i] << " ";

    cout << endl;

    return 0;
}
