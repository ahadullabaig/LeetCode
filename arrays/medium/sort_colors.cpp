#include <bits/stdc++.h>

using namespace std;

void my_sortColors(vector<int> &nums) // my version of O(n) and O(1), which is valid
{
    int slot = 0;

    int i = 0;

    while(i < nums.size())
    {
        if(nums[i] == 0)
        {
            swap(nums[slot], nums[i]);
            slot++;
        }

        i++;
    }

    i = slot;

    while(i < nums.size())
    {
        if(nums[i] == 1)
        {
            swap(nums[slot], nums[i]);
            slot++;
        }

        i++;
    }
}

void dnf_sortColors(vector<int> &nums) // dutch national flag algorithm
{
    int n = nums.size();

    int low = 0, mid = 0, high = n-1;

    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++; mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    dnf_sortColors(nums);

    for(int x : nums) cout << x << " ";

    cout << endl;

    return 0;
}
