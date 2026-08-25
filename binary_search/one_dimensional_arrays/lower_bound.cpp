#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &nums, int target)
{
    int lower = nums.size(); // if lower isn't updated then we return n

    int left = 0, right = nums.size()-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] >= target)
        {
            lower = mid;

            right = mid-1;
        }

        else left = mid+1; // nums[mid] < target

        // no seperate else condition to check for nums[mid] > target cuz the first if condition is >=.
    }

    return lower;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8};

    int target = 5;

    cout << lowerBound(nums, target) << endl;

    return 0;
}
