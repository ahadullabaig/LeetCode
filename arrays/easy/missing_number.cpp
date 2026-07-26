#include <bits/stdc++.h>

using namespace std;

int bf_leetcode(vector<int> &nums)
{
    int n = nums.size();

    vector<int> arr(n+1, 0);

    for(int x : nums) arr[x] = 1;

    for(int i=0; i < (n+1); i++)
    {
        if(arr[i] == 0) return i;
    }

    return -1;
}

int sum_leetcode(vector<int> &nums)
{
    int n = nums.size();

    int total = (n*(n+1))/2;

    int sum = 0;

    for(int x : nums) sum += x;

    return total - sum;
}

int xor_leetcode(vector<int> &nums)
{
    int n = nums.size();

    int num = 0;

    for(int i=0; i<=n; i++) num ^= i;

    for(int x : nums) num ^= x;

    return num;
}

int main()
{
    vector<int> arr = {1, 2, 3, 0};

    cout << xor_leetcode(arr) << endl;

    return 0;
}
