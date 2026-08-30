#include <bits/stdc++.h>

using namespace std;

int minimumDeletions(vector<int> &nums)
{
    int n = nums.size();

    if(n == 1) return 1;

    int maximum = 0, minimum = 0;

    for(int i=0; i<n; i++)
    {
        if(nums[i] > nums[maximum]) maximum = i;

        if(nums[i] < nums[minimum]) minimum = i;
    }

    int left = max(maximum, minimum) + 1;

    int right = n - min(maximum, minimum);

    if(minimum < maximum)
    {
        return min(left, min(right, minimum+1 + n-maximum));
    }
    else
    {
        return min(left, min(right, maximum+1 + n-minimum));
    }
}

int main()
{
    vector<int> nums = {-1, -53, 93, -42, 37, 94, 97, 82, 46, 42, -99, 56, -76, -66, -67, -13, 10, 66, 85, -28};

    cout << minimumDeletions(nums) << endl;

    return 0;
}
