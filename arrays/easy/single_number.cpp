#include <bits/stdc++.h>

using namespace std;

int single_number_1(vector<int> &nums)
{
    int num = 0;
    
    for(int x : nums) num ^= x;

    return num;
}

int single_number_2(vector<int> &nums)
{
    int ans = 0;
    
    for(int i=0; i<32; i++)
    {
        int count = 0;

        for(int x : nums)
        {
            if(x & (1 << i)) count++;
        }

        if(count % 3 == 1) ans |= (1 << i);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 3};

    cout << single_number_2(arr) << endl;

    return 0;
}
