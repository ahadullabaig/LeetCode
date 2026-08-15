#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> triplets;

    int n = nums.size();

    for(int i=0; i < n-2; i++) // stopping condition is i < n-2 cuz we need at least 3 elements to form a triplet
    {
        if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicate first elements

        int left = i+1, right = n-1;

        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0)
            {
                triplets.push_back({nums[i], nums[left], nums[right]});

                while(left < right && nums[left] == nums[left+1]) left++; // Skip duplicate second elements

                while(left < right && nums[right] == nums[right-1]) right--; // Skip duplicate third elements

                left++; right--;
            }

            else if(sum < 0)
            {
                left++;
            }
            
            else
            {
                right--;
            }
        }
    }

    return triplets;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> triplets = threeSum(nums);

    for(auto triplet : triplets)
    {
        for(int x : triplet) cout << x << " ";

        cout << endl;
    }

    return 0;
}
