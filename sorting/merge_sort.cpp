#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;

    int l = left, r = mid+1;

    while(l <= mid && r <= right)
    {
        if(arr[l] <= arr[r])
        {
            temp.push_back(arr[l]);
            l++;
        }
        else
        {
            temp.push_back(arr[r]);
            r++;
        }
    }

    while(l <= mid)
    {
        temp.push_back(arr[l]);
        l++;
    }

    while(r <= right)
    {
        temp.push_back(arr[r]);
        r++;
    }

    for(int i=left; i<=right; i++)
        arr[i] = temp[i - left];
}

void mergesort(vector<int> &arr, int left, int right)
{
    if(left >= right) return;

    int mid = (left + right) / 2;
    
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 1, 1, 1, 7, 8, 2, 3};

    mergesort(arr, 0, arr.size() - 1);

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
