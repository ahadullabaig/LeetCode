#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maximum = 0;

    int left=0, right=0;

    int n = nums.size();

    while(left < n && right < n)
    {
        if(nums[right] != 1)
        {
            if(maximum < (right - left))
                maximum = right - left;

            right++;
            left = right;
        }
        else
        {
            right++;
        }
    }

    if(maximum < (right - left))
        maximum = right - left;

    return maximum;
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

    cout << findMaxConsecutiveOnes(arr) << endl;

    return 0;
}
