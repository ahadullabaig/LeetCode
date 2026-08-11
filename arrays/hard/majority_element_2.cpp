#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();

    vector<int> majors;

    unordered_map<int, int> counts;

    for(int x : nums) counts[x]++;

    for(auto [num, count] : counts)
    {
        if(count > n/3) majors.push_back(num);
    }

    return majors;
}

int main()
{
    vector<int> nums = {3, 2, 3};

    vector<int> majors = majorityElement(nums);

    for(int x : majors) cout << x << " ";

    cout << endl;

    return 0;
}
