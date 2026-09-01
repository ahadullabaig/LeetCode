#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] > nums[mid+1]) return mid+1;

        if(nums[left] <= nums[mid]) left = mid+1;

        else right = mid;
    }

    return 0;
}

int main()
{
    vector<int> nums = {3, 4, 5, 6, 7, 8, 1, 2};

    cout << count(nums) << endl;

    return 0;
}
