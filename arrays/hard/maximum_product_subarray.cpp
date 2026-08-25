#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &nums)
{
    int maximum = INT_MIN;
    
    int max_prod = 1, min_prod = 1;
    
    for(int x : nums)
    {
        int mxp = max_prod, mnp = min_prod; // to prevent using updated values

        max_prod = max({x, x*mxp, x*mnp});

        min_prod = min({x, x*mxp, x*mnp});
        
        maximum = max(maximum, max_prod);
    }
    
    return maximum;
}

int crazy_maxProduct(vector<int> &nums)
{
    int maximum = INT_MIN;

    int n = nums.size();

    int prod = 1;

    for(int i=0; i<n; i++)
    {
        prod *= nums[i];

        maximum = max(maximum, prod);

        if(prod == 0) prod = 1;
    }

    prod = 1;

    for(int i = n-1; i>=0; i--)
    {
        prod *= nums[i];

        maximum = max(maximum, prod);

        if(prod == 0) prod = 1;
    }

    return maximum;
}

int main()
{
    vector<int> nums = {2, -5, -2, -4, 3};

    cout << maxProduct(nums) << endl;

    cout << crazy_maxProduct(nums) << endl;

    return 0;
}
