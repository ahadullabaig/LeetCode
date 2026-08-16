#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) // O(n*n*n)
{
    int sum = 0, closeness = INT_MAX;

    int n = nums.size();

    for(int i=0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                int total = nums[i] + nums[j] + nums[k];

                if(total == target) return total;

                if(abs(target - total) < closeness)
                {
                    sum = total;

                    closeness = abs(target - total);
                }
            }
        }
    }

    return sum;
}

int op_threeSumClosest(vector<int> &nums, int target) // O(n*n)
{
    sort(nums.begin(), nums.end());

    int sum = 0, closeness = INT_MAX;

    int n = nums.size();

    for(int i=0; i < n-2; i++)
    {
        int left = i+1, right = n-1;

        while(left < right)
        {
            int total = nums[i] + nums[left] + nums[right];

            if(total == target) return total;

            if(abs(target - total) < closeness)
            {
                sum = total;

                closeness = abs(target - total);
            }

            if(total > target)
                right--;
            else
                left++;
        }
    }

    return sum;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};

    int target = 1;

    cout << op_threeSumClosest(nums, target) << endl;

    return 0;
}
