#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int k = 1;

    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] != nums[k-1])
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums);

    for(int x : nums) cout << x << " ";

    cout << endl << k << endl;

    return 0;
}
