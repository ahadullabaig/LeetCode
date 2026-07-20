#include <bits/stdc++.h>

using namespace std;

int maxFrequency(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());

    map<int, int> counts;

    for(int i=0; i<nums.size(); i++)
    {
        int ops = k;

        for(int j=i; j>=0; j--)
        {
            if(ops == 0) break;

            if((nums[j] + ops) >= nums[i])
            {
                counts[nums[i]]++;
                ops = (nums[j] + ops) - nums[i];
            }
        }

        if(i != nums.size()-1)
            while(nums[i+1] == nums[i])
                counts[nums[i++]]++;
    }

    int most = 0;

    for(auto x : counts)
    {
        if(x.second > most)
            most = x.second;
    }

    return most;
}

int main()
{
    int n = 2;
    return 0;
}
