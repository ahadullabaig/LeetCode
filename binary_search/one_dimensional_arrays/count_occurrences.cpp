#include <bits/stdc++.h>

using namespace std;

int countOccurrences(vector<int> &nums, int target)
{
    int n = nums.size();

    if(n == 0) return 0;

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

    if(lower == -1 || nums[lower] != target) return 0;

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

    upper = (upper == -1) ? n : upper;

    return upper - lower;
}

int main()
{
    vector<int> nums = {1, 5, 5, 5, 5, 5, 5, 5, 5, 10};

    int target = 5;

    cout << countOccurrences(nums, target) << endl;

    return 0;
}
