#include <bits/stdc++.h>

using namespace std;

bool uniformArray(vector<int> &nums1) // O(n*n)
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

                if((nums1[j] + nums1[i])%2 == 0 || (nums1[j] - nums1[i])%2 == 0)
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
            bool flag = false;

            for(int j=0; j<n; j++)
            {
                if(j == i) continue;

                if((nums1[j] + nums1[i])%2 != 0 || (nums1[j] - nums1[i])%2 != 0)
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

bool op_uniformArray(vector<int> &nums1) // O(1)
{
    /*
        We can ALWAYS construct a valid nums2. Therefore, the answer is always true.

        Case 1:
        If all elements in nums1 have the same parity, return true.


        Case 2:
        nums1 contains both odd and even numbers.

        Since there is at least one odd number, choose any odd number nums1[j] as our "converter".

        - If nums1[i] is odd:
              choose nums2[i] = nums1[i]
              -> remains odd

        - If nums1[i] is even:
              choose nums2[i] = nums1[i] - nums1[j]
              -> even - odd = odd

        Therefore, every element of nums2 can be made ODD.

        Hence, regardless of what nums1 looks like,
        constructing a uniform-parity nums2 is ALWAYS possible.

        So the answer is ALWAYS true.
    */

    return true;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    cout << uniformArray(nums) << endl;

    cout << op_uniformArray(nums) << endl;

    return 0;
}
