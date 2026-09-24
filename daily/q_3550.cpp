#include <bits/stdc++.h>

using namespace std;

int smallestIndex(vector<int> &nums)
{
    int n = nums.size();

    for(int i=0; i<n; i++)
    {
        int num = nums[i], sum = 0;

        while(num > 0)
        {
            sum += num % 10;

            num /= 10;
        }

        if(sum == i) return i;
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 5};

    cout << smallestIndex(nums) << endl;

    return 0;
}
