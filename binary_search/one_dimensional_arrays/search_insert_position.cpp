#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int pos = 0;

    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target) return mid;

        else if(nums[mid] > target)
        {
            pos = mid;

            right = mid-1;
        }

        else
        {
            left = mid+1;

            pos = left;
        }
    }

    return pos;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    int target = 0;

    cout << searchInsert(nums, target) << endl;

    return 0;
}
