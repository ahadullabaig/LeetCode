#include <bits/stdc++.h>

using namespace std;

vector<int> my_rearrangeArray(vector<int> &nums) // O(n)
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

vector<int> op_rearrangeArray(vector<int> &nums) // O(n)
{
    int n = nums.size();

    vector<int> alternating(n);

    int pos = 0, neg = 1;

    for(int x : nums)
    {
        if(x > 0)
        {
            alternating[pos] = x;

            pos += 2;
        }
        else
        {
            alternating[neg] = x;

            neg += 2;
        }
    }

    return alternating;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> alternating = op_rearrangeArray(nums);

    for(int x : alternating) cout << x << " ";

    cout << endl;

    return 0;
}
