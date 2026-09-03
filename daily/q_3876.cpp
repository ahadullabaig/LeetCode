#include <bits/stdc++.h>

using namespace std;

bool bf_uniformArray(vector<int> &nums1) // O(n*n)
{
    int n = nums1.size();

    bool flag = true;

    for(int i=0; i<n; i++)
    {
        if(nums1[i]%2 != 0)
        {
            flag = false;

            for(int j=0; j<n; j++)
            {
                if(j == i) continue;

                if(nums1[i] > nums1[j] && (nums1[i] - nums1[j])%2 == 0)
                {
                    flag = true;
                    break;
                }
            }

            if(!flag) break;
        }
    }

    if(flag) return true;

    flag = true;

    for(int i=0; i<n; i++)
    {
        if(nums1[i]%2 == 0)
        {
            flag = false;

            for(int j=0; j<n; j++)
            {
                if(j == i) continue;

                if(nums1[i] > nums1[j] && (nums1[i] - nums1[j])%2 != 0)
                {
                    flag = true;
                    break;
                }
            }

            if(!flag) break;
        }
    }

    return flag;
}

int main()
{
    vector<int> nums = {2, 3};

    cout << bf_uniformArray(nums) << endl;

    return 0;
}
