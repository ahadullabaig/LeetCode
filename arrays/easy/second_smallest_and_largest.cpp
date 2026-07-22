#include <bits/stdc++.h>

using namespace std;

vector<int> second_smallest_and_largest(vector<int> &arr)
{
    if(arr.size() < 2) return {-1};
    
    int smallest = arr[0], largest = arr[0];

    for(int x : arr)
    {
        if(x < smallest) smallest = x;

        if(x > largest) largest = x;
    }

    int ss = INT_MAX, sl = INT_MIN;

    for(int x : arr)
    {
        if(x < ss && x > smallest) ss = x;

        if(x > sl && x < largest) sl = x;
    }

    if(ss == INT_MAX || sl == INT_MIN) return {-1};

    return {ss, sl};
}

int main()
{
    vector<int> arr = {8, 9, 1, 2, 3, 4, 5, 6, 7};

    vector<int> nums = second_smallest_and_largest(arr);

    cout << "Second Smallest and Largest Elements: " << nums[0] << " & " << nums[1] << endl;
    
    return 0;
}
