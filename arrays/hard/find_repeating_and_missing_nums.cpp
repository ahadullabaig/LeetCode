#include <bits/stdc++.h>

using namespace std;

vector<int> rep_and_missing(vector<int> &nums)
{
    unordered_map<int, int> count;

    for(int x : nums) count[x]++;

    vector<int> ans;

    for(auto [num, freq] : count)
    {
        if(freq == 2) ans.push_back(num);
    }

    int n = nums.size();

    for(int i=1; i <= n; i++)
    {
        if(!count.contains(i))
        {
            ans.push_back(i);
            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 5, 4, 1, 1};

    vector<int> ans = rep_and_missing(nums);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
