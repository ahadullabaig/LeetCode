#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int> &nums, int target)
{
    int upper = nums.size(); // if upper isn't updated then we return n

    int left = 0, right = nums.size()-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] > target)
        {
            upper = mid;

            right = mid-1;
        }

        else left = mid+1; // nums[mid] <= target
    }

    return upper;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8};

    int target = 5;

    cout << upperBound(nums, target) << endl;

    return 0;
}
