#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums)
{
    int slot = 0;

    int i = 0;

    while(i < nums.size())
    {
        if(nums[i] == 0)
        {
            swap(nums[slot], nums[i]);
            slot++;
        }

        i++;
    }

    i = slot;

    while(i < nums.size())
    {
        if(nums[i] == 1)
        {
            swap(nums[slot], nums[i]);
            slot++;
        }

        i++;
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    for(int x : nums) cout << x << " ";

    cout << endl;

    return 0;
}
