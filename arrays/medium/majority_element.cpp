#include <bits/stdc++.h>

using namespace std;

int my_majorityElement(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> counts;

    for(int x : nums)
    {
        counts[x]++;

        if(counts[x] > n/2) return x;
    }

    return 0;
}

int bm_majorityElement(vector<int> &nums) // Boyer–Moore algorithm
{
    int n = nums.size();

    int candidate = -1;
    
    int count = 0;

    for(int x : nums)
    {
        if(count == 0)
        {
            candidate = x;
            count++;
        }
        else
        {
            if(x == candidate) count++;
            else count--;
        }
    }

    count = 0;

    for(int x : nums)
        if(x == candidate)
            count++;

    if(count > n/2) return candidate;

    return -1;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << bm_majorityElement(nums) << endl;

    return 0;
}
