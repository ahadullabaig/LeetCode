#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> seen;

    for(int i=0; i<nums.size(); i++)
    {
        int required = target - nums[i];

        if(seen.contains(required))
        {
            return {i, seen[required]};
        }
        else
        {
            seen[nums[i]] = i;
        }
    }

    return {};
}

int main()
{
    vector<int> nums = {7, 1, 2, 3, 4, 5, 6};

    vector<int> indices = twoSum(nums, 11);

    cout << indices[0] << " " << indices[1] << endl;
    
    return 0;
}
