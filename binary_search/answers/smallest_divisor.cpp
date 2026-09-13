#include <bits/stdc++.h>

using namespace std;

int smallestDivisor(vector<int> &nums, int threshold)
{
    int left = 1, right = 1;

    for(int x : nums) right = max(right, x);

    while(left < right)
    {
        int mid = (left + right) / 2;

        int sum = 0;

        for(int x : nums) sum += (x%mid == 0) ? (x/mid) : (x/mid)+1;

        if(sum <= threshold) right = mid;

        else left = mid+1;
    }

    return right;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};

    int threshold = 6;

    cout << smallestDivisor(nums, threshold) << endl;

    return 0;
}
