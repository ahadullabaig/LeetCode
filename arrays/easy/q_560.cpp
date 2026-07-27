#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int total = 0;

    unordered_map<int, int> sums;
    sums[0] = 1;

    int prefix = 0;

    for(int x : nums)
    {
        prefix += x;

        total += sums[prefix - k];

        sums[prefix]++;
    }

    return total;
}

int main()
{
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};

    cout << subarraySum(arr, 0) << endl;

    return 0;
}
