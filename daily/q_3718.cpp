#include <bits/stdc++.h>

using namespace std;

int missingMultiple(vector<int> &nums, int k)
{
    unordered_set<int> multiples;

    for(int x : nums)
    {
        if(x%k == 0) multiples.insert(x);
    }

    for(int i = k; i < INT_MAX; i += k)
    {
        if(!multiples.contains(i)) return i;
    }

    return 0;
}

int main()
{
    vector<int> nums = {1, 4, 7, 10, 15};

    int k = 5;

    cout << missingMultiple(nums, k) << endl;

    return 0;
}
