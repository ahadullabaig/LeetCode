#include <bits/stdc++.h>

using namespace std;

vector<int> my_majorityElement(vector<int> &nums)
{
    int n = nums.size();

    vector<int> majors;

    unordered_map<int, int> counts;

    for(int x : nums) counts[x]++;

    for(auto [num, count] : counts)
    {
        if(count > n/3) majors.push_back(num);
    }

    return majors;
}

vector<int> op_majorityElement(vector<int> &nums) // extended Boyer–Moore. O(1) space complexity
{
    int major_1 = INT_MIN, major_2 = INT_MIN;

    int count_1 = 0, count_2 = 0;
    
    for(int x : nums)
    {
        if(x == major_1)
            count_1++;

        else if(x == major_2)
            count_2++;

        else if(count_1 == 0)
        {
            major_1 = x;
            count_1 = 1;
        }

        else if(count_2 == 0)
        {
            major_2 = x;
            count_2 = 1;
        }

        else
        {
            count_1--;
            count_2--;
        }
    }

    count_1 = count_2 = 0;

    for(int x : nums)
    {
        if(x == major_1) count_1++;

        else if(x == major_2) count_2++;
    }

    int n = nums.size();

    if(count_1 > n/3 && count_2 > n/3)
    {
        return {major_1, major_2};
    }
    else if(count_1 > n/3)
    {
        return {major_1};
    }
    else if(count_2 > n/3)
    {
        return {major_2};
    }
    else return {};
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 5, 2, 2, 2, 2, 10};

    vector<int> majors = op_majorityElement(nums);

    for(int x : majors) cout << x << " ";

    cout << endl;

    return 0;
}
