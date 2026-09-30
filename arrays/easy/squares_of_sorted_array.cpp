#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans;

    if(nums[0] >= 0)
    {
        for(int x : nums) ans.push_back(x*x);

        return ans;
    }

    if(nums[n-1] < 0)
    {
        for(int i = n-1; i>=0; i--) ans.push_back(nums[i] * nums[i]);

        return ans;
    }

    int fp, fn;

    for(int i=0; i<n; i++)
    {
        if(nums[i] >= 0)
        {
            fp = i;
            fn = i-1;
            break;
        }
    }

    if(nums[fp] == 0)
    {
        ans.push_back(0);
        fp++;
    }

    while(fn >= 0 && fp < n)
    {
        if(abs(nums[fn]) < nums[fp])
        {
            ans.push_back(nums[fn] * nums[fn]);
            fn--;
        }
        else
        {
            ans.push_back(nums[fp] * nums[fp]);
            fp++;
        }
    }

    while(fn >= 0)
    {
        ans.push_back(nums[fn] * nums[fn]);
        fn--;
    }

    while(fp < n)
    {
        ans.push_back(nums[fp] * nums[fp]);
        fp++;
    }

    return ans;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 2, 4};

    vector<int> ans = sortedSquares(nums);

    for(int x : ans) cout << x << " ";

    cout << endl;

    return 0;
}
