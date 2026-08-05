#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> alternating;

    int n = nums.size();

    int pos = 0, neg = 0;

    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            while(nums[pos] < 0) pos++;

            alternating.push_back(nums[pos]);

            pos++;
        }
        else
        {
            while(nums[neg] > 0) neg++;

            alternating.push_back(nums[neg]);

            neg++;
        }
    }

    return alternating;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> alternating = rearrangeArray(nums);

    for(int x : alternating) cout << x << " ";

    cout << endl;

    return 0;
}
