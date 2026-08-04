#include <bits/stdc++.h>

using namespace std;

vector<int> my_findMissingElements(vector<int> &nums) // O(n*log(n))
{
    vector<int> missing;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for(int i=0; i < (n-1); i++)
    {
        if(nums[i+1] != (nums[i] + 1))
        {
            int missed = nums[i] + 1;

            while(missed != nums[i+1])
            {
                missing.push_back(missed);
                missed++;
            }
        }   
    }

    return missing;
}

vector<int> expected_findMissingElements(vector<int> &nums) // O(n)
{
    vector<int> missing;

    unordered_set<int> present;

    int smallest = nums[0], largest = nums[0];

    for(int x : nums)
    {
        present.insert(x);
        smallest = min(x, smallest);
        largest = max(x, largest);
    }

    for(int i = (smallest + 1); i < largest; i++)
    {
        if(!present.contains(i))
        {
            missing.push_back(i);
        }
    }

    return missing;
}

int main()
{
    vector<int> nums = {0, 10};

    vector<int> missing = my_findMissingElements(nums);

    for(int x : missing) cout << x << " ";

    cout << endl;

    return 0;
}
