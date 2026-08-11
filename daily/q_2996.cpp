#include <bits/stdc++.h>

using namespace std;

int missingInteger(vector<int> &nums)
{
    int n = nums.size();

    int sum = nums[0];

    for(int i=1; i<n; i++)
    {
        if(nums[i] == (nums[i-1] + 1))
        {
            sum += nums[i];
        }

        else break;
    }

    unordered_set<int> present;

    for(int x : nums) present.insert(x);

    while(true)
    {
        if(!present.contains(sum)) return sum;

        sum += 1;
    }

    return 0;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 8, 8, 9, 4, 3, 2, 7};

    cout << missingInteger(nums) << endl;

    return 0;
}
