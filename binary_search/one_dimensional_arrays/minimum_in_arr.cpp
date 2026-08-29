#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{
    int minimum = nums[0];

    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] < minimum) minimum = nums[mid];

        if(nums[left] < minimum) minimum = nums[left];

        if(nums[right] < minimum) minimum = nums[right];

        if(nums[left] <= nums[mid])
        {
            if(nums[left] > minimum) left = mid+1;

            else right = mid-1;
        }

        else
        {
            if(minimum > nums[right]) left = mid+1;

            else right = mid-1;
        }
    }

    return minimum;
}

int op_findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] > nums[right]) left = mid+1;

        else right = mid;
    }

    return nums[left];
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << findMin(nums) << endl;

    cout << op_findMin(nums) << endl;

    return 0;
}
