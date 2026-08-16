#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if(n == 0) return;

    int i = m-1, j = n-1;

    int slot = m + n - 1;

    while(i >= 0 && j >= 0)
    {
        if(nums2[j] > nums1[i])
        {
            nums1[slot] = nums2[j];
            j--; slot--;
        }
        else
        {
            swap(nums1[i], nums1[slot]);
            i--; slot--;
        }
    }

    while(j >= 0)
    {
        nums1[slot] = nums2[j];
        j--; slot--;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};

    vector<int> nums2 = {2, 5, 6};

    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

    for(int x : nums1) cout << x << " ";

    cout << endl;

    return 0;
}
