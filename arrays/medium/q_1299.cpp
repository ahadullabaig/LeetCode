#include <bits/stdc++.h>

using namespace std;

vector<int> replaceElements(vector<int> &arr)
{
    int n = arr.size();

    vector<int> nums = {-1};

    int largest = arr[n-1];

    for(int i=n-2; i>=0; i--)
    {
        nums.push_back(largest);

        largest = max(largest, arr[i]);
    }

    reverse(nums.begin(), nums.end());

    return nums;
}

int main()
{
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> nums = replaceElements(arr);

    for(int x : nums) cout << x << " ";

    cout << endl;
    
    return 0;
}
