#include <bits/stdc++.h>

using namespace std;

int sqrt_binary_search(int n)
{
    if(n <= 0) return 0;

    int left = 1, right = n;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        long long prod = 1LL * mid * mid;

        if(prod == n) return mid;

        else if(prod < n) left = mid+1;

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
