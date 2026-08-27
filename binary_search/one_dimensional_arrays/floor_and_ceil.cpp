#include <bits/stdc++.h>

using namespace std;

vector<int> floor_and_ceil(vector<int> &nums, int target)
{
    int floor = -1, ceil = -1;

    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target) return {mid, mid};

        else if(nums[mid] > target)
        {
            ceil = mid;

            right = mid-1;
        }

        else
        {
            floor = mid;

            left = mid+1;
        }
    }

    return {floor, ceil};
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8};

    int target = 5;

    vector<int> arr = floor_and_ceil(nums, target);

    cout << arr[0] << " " << arr[1] << endl;

    return 0;
}
