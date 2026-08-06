#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if(nums.size() == 0) return 0;

    unordered_set<int> seen;

    for(int x : nums) seen.insert(x);

    int longest = 1;

    for(int x : seen)
    {
        if(!seen.contains(x - 1))
        {
            int length = 1;

            for(int num=x; seen.contains(num + 1); num++)
            {
                longest = max(longest, ++length);
            }
        }
    }

    return longest;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    cout << longestConsecutive(nums) << endl;

    return 0;
}
