#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();

    int zero = -1;

    for(int i=0; i<n; i++)
    {
        if(nums[i] == 0)
        {
            zero = i;
            break;
        }
    }

    if(zero == -1) return;

    int num = zero;

    while(zero < n && num < n)
    {
        if(nums[zero] != 0)
        {
            zero++;
            continue;
        }

        if(nums[num] == 0)
        {
            num++;
            continue;
        }

        if(nums[zero] == 0 && nums[num] != 0)
        {
            swap(nums[zero], nums[num]);
            zero++;
            num++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    for(int x : nums) cout << x << " ";

    cout << endl;

    return 0;
}
