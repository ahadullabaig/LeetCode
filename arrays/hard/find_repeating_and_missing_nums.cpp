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

vector<int> sums_rep_and_missing(vector<int> &nums) // O(1) space complexity
{
    int n = nums.size();

    int expectedSum1 = ((n + 1) * n) / 2;

    int expectedSum2 = ((2*n + 1) * (n + 1) * n) / 6;

    int actualSum1 = 0, actualSum2 = 0;

    for(int x : nums)
    {
        actualSum1 += x;

        actualSum2 += x*x;
    }

    int eq1 = actualSum1 - expectedSum1; // (A - B)

    int eq2 = actualSum2 - expectedSum2; // (A - B) * (A + B)

    int eq3 = eq2 / eq1; // (A + B)

    int repeated = (eq3 + eq1) / 2; // A

    int missing = (eq3 - eq1) / 2; // B

    return {repeated, missing};
}

vector<int> xor_rep_and_missing(vector<int> &nums) // O(1) space complexity
{
    int n = nums.size();

    int x = 0;

    for(int i=1; i <= n; i++) x ^= i;

    for(int num : nums) x ^= num;

    // now x contains A ^ B

    int bit = x & -x; // trick to get rightmost set bit

    int group1 = 0, group2 = 0;

    // split expected numbers into two groups
    for(int i=1; i <= n; i++)
    {
        if(i & bit)
            group1 ^= i;
        else
            group2 ^= i;
    }

    // split actual numbers into two groups
    for(int num : nums)
    {
        if(num & bit)
            group1 ^= num;
        else
            group2 ^= num;
    }

    // group1 and group2 are {A, B}, but we don't know which is which

    for(int num : nums)
    {
        if(num == group1) return {group1, group2};
    }

    return {group2, group1};
}

int main()
{
    vector<int> nums = {1, 2, 3, 6, 7, 5, 7};

    vector<int> ans = rep_and_missing(nums);

    cout << ans[0] << " " << ans[1] << endl;

    ans = sums_rep_and_missing(nums);

    cout << ans[0] << " " << ans[1] << endl;

    ans = xor_rep_and_missing(nums);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
