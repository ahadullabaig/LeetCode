#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> &arr)
{
    int n = arr.size();

    for(int i=0; i < (n-1); i++)
    {
        if(arr[i] > arr[i+1]) return false;
    }

    return true;
}

bool leetcode(vector<int> &nums)
{
    int n = nums.size();

    int counter = 0;

    for(int i=0; i<n; i++)
    {
        if(nums[i] > nums[(i+1) % n])
        {
            counter++;
        }
    }

    return counter <= 1;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 7, 9};

    if(isSorted(arr)) cout << "Array is Sorted" << endl;
    else cout << "Array is not Sorted" << endl;

    return 0;
}
