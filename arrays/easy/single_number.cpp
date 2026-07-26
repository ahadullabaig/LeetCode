#include <bits/stdc++.h>

using namespace std;

int single_number(vector<int> &nums)
{
    int num = 0;
    
    for(int x : nums) num ^= x;

    return num;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3};

    cout << single_number(arr) << endl;

    return 0;
}
