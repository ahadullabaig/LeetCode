#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();

    int left = 0, right = n-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target) return true;

        else if(nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
        }

        else if(nums[left] <= nums[mid])
        {
            if(nums[left] <= target && target < nums[mid]) right = mid-1;

            else left = mid+1;
        }

        else
        {
            if(nums[mid] < target && target <= nums[right]) left = mid+1;

            else right = mid-1;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 1};

    int target = 0;

    cout << search(nums, target) << endl;

    return 0;
}
