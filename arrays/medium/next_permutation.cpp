#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    int pivot = -1;

    for(int i = (n-2); i>=0; i--)
    {
        if(nums[i] < nums[i+1])
        {
            pivot = i;
            break;
        }
    }

    if(pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    int smallest = pivot + 1;

    for(int i=n-1; i > pivot; i--)
    {
        if(nums[i] > nums[pivot])
        {
            smallest = i;
            break; // since everything to right of pivot is in descending order
        }
    }

    swap(nums[pivot], nums[smallest]);

    // we reverse instead of sort cuz everything to right of pivot is in descending order
    reverse(nums.begin() + pivot + 1, nums.end());
}

int main()
{
    vector<int> nums = {2, 3, 1, 3, 3};

    nextPermutation(nums);

    for(int x : nums) cout << x << " ";

    cout << endl;

    return 0;
}
