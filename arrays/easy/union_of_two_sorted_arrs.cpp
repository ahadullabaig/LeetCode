#include <bits/stdc++.h>

using namespace std;

vector<int> union_of_arrs(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> arr;

    int n = arr1.size(), m = arr2.size();

    int i=0, j=0;

    while(i<n && j<m)
    {
        if(arr1[i] <= arr2[j])
        {
            if(arr.empty() || arr1[i] != arr.back())
                arr.push_back(arr1[i]);

            i++;
        }
        else
        {
            if(arr.empty() || arr2[j] != arr.back())
                arr.push_back(arr2[j]);
            
            j++;
        }
    }

    while(i < n)
    {
        if(arr.empty() || arr1[i] != arr.back())
            arr.push_back(arr1[i]);

        i++;
    }

    while(j < m)
    {
        if(arr.empty() || arr2[j] != arr.back())
            arr.push_back(arr2[j]);

        j++;
    }

    return arr;
}

void leetcode(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int l = m-1, r = n-1;

    int slot = m+n-1;

    while(l >= 0 && r >= 0)
    {
        if(nums2[r] >= nums1[l])
        {
            nums1[slot] = nums2[r];
            r--;
        }
        else
        {
            nums1[slot] = nums1[l];
            l--;
        }

        slot--;
    }

    while(r >= 0)
    {
        nums1[slot] = nums2[r];
        r--; slot--;
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};

    leetcode(arr1, 3, arr2, 3);

    for(int x : arr1) cout << x << " ";

    cout << endl;

    return 0;
}
