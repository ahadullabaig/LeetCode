#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == nums[mid ^ 1]) left = mid+1;

        else right = mid;
    }

    return nums[left];
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5};

    cout << singleNonDuplicate(nums) << endl;

    return 0;
}
