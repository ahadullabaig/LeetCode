#include <bits/stdc++.h>

using namespace std;

int mergeCount(vector<int> &nums, int left, int mid, int right)
{
    int count = 0;

    vector<int> temp;

    int l = left, r = mid+1;

    while(l <= mid && r <= right)
    {
        if(nums[l] <= nums[r])
        {
            temp.push_back(nums[l]);
            l++;
        }
        else
        {
            temp.push_back(nums[r]);
            r++;

            count += mid - l + 1;
        }
    }

    while(l <= mid)
    {
        temp.push_back(nums[l]);
        l++;
    }

    while(r <= right)
    {
        temp.push_back(nums[r]);
        r++;
    }

    for(int i=left; i<=right; i++)
        nums[i] = temp[i - left];

    return count;
}

int mergeSort(vector<int> &nums, int left, int right)
{
    int count = 0;

    if(left < right)
    {
        int mid = (left + right) / 2;

        count += mergeSort(nums, left, mid);

        count += mergeSort(nums, mid+1, right);

        count += mergeCount(nums, left, mid, right);
    }

    return count;
}

int main()
{
    vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int n = nums.size();

    cout << mergeSort(nums, 0, n-1) << endl;

    return 0;
}
