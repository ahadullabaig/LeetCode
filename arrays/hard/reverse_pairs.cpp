#include <bits/stdc++.h>

using namespace std;

int bf_reversePairs(vector<int> &nums) // O(n*n)
{
    int n = nums.size();

    int count = 0;

    for(int i=0; i < n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            long long j_2 = 1LL * nums[j] * 2;

            if(nums[i] > j_2) count++;
        }
    }

    return count;
}

int mergeCount(vector<int> &nums, int left, int mid, int right)
{
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

    int count = 0;

    l = left, r = mid+1;

    while(l <= mid && r <= right)
    {
        long long prod = 1LL * nums[r] * 2;

        if(nums[l] > prod)
        {
            count += mid - l + 1;
            
            r++;
        }

        else l++;
    }

    for(int i = left; i <= right; i++)
    {
        nums[i] = temp[i - left];
    }

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

int op_reversePairs(vector<int> &nums) // O(n*log(n))
{
    return mergeSort(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> nums = {2, 4, 3, 5, 1};

    cout << bf_reversePairs(nums) << endl;

    cout << op_reversePairs(nums) << endl;

    return 0;
}
