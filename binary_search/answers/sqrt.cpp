#include <bits/stdc++.h>

using namespace std;

int sqrt_binary_search(int n)
{
    int left = 0, right = n;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(mid*mid == n) return mid;

        else if(mid*mid < n) left = mid+1;

        else right = mid-1;
    }

    return right;
}

int main()
{
    int n = 29;

    cout << sqrt_binary_search(n) << endl;

    return 0;
}
