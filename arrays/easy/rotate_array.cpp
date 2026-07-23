#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();

    k %= n;

    n -= k;

    vector<int> temp;

    for(int i=0; i<k; i++)
        temp.push_back(nums[n++]);

    for(int i=0; i<(n-k); i++) 
        temp.push_back(nums[i]);

    nums = temp;
}

void op_rotate(vector<int> &nums, int k)
{
    int n = nums.size();

    k %= n;

    for(int i=0; i<(n/2); i++)
        swap(nums[i], nums[n-1-i]);

    for(int i=0; i<(k/2); i++)
        swap(nums[i], nums[k-1-i]);

    for(int i=0; i < ((n-k)/2); i++)
        swap(nums[k+i], nums[n-1-i]);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    op_rotate(arr, 3);

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
