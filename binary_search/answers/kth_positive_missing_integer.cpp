#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();

    int left = 0, right = n-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        int missing = arr[mid] - (mid+1);

        if(missing >= k) right = mid-1;

        else left = mid+1;
    }

    if(right == -1) return k;

    int missing_till_now = arr[right] - (right+1);

    return arr[right] + (k - missing_till_now);
}

int main()
{
    vector<int> arr = {7, 13, 21, 25, 29, 32, 38, 45};

    int k = 4;

    cout << findKthPositive(arr, k) << endl;

    return 0;
}
