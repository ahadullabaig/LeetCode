#include <bits/stdc++.h>

using namespace std;

vector<int> leadersOfArray(vector<int> &nums)
{
    int n = nums.size();

    vector<int> leaders = {nums[n-1]};

    int largest = nums[n-1];

    for(int i=n-2; i>=0; i--)
    {
        if(nums[i] >= largest)
        {
            leaders.push_back(nums[i]);

            largest = nums[i];
        }
    }

    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main()
{
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> leaders = leadersOfArray(nums);

    for(int x : leaders) cout << x << " ";

    cout << endl;

    return 0;
}
