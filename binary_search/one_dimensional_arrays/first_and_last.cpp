#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();

    if(n == 0) return {-1, -1};

    int lower = -1;

    int left = 0, right = n-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] >= target)
        {
            lower = mid;

            right = mid-1;
        }

        else left = mid+1;
    }

    if(lower == -1 || nums[lower] != target) return {-1, -1};

    int upper = -1;

    left = 0, right = n-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] > target)
        {
            upper = mid;

            right = mid-1;
        }

        else left = mid+1;
    }

    upper = (upper == -1) ? n-1 : upper-1;

    return {lower, upper};
}

int main()
{
    vector<int> nums = {1, 2, 5, 5, 5, 5, 5, 5, 8};

    int target = 5;

    vector<int> arr = searchRange(nums, target);

    cout << arr[0] << " " << arr[1] << endl;

    return 0;
}
