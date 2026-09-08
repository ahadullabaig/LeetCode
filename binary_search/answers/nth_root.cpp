#include <bits/stdc++.h>

using namespace std;

int nth_root_binary_search(int n, int m)
{
    if(m <= 0) return 0;

    int left = 1, right = m;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        long long prod = 1LL;

        for(int i=0; i<n; i++)
        {
            prod *= mid;

            if(prod > m) break; // prevents long long overflow
        }

        if(prod == m) return mid;

        else if(prod < m) left = mid+1;

        else right = mid-1;
    }

    return -1;
}

int main()
{
    int n = 2, m = 1024;

    cout << nth_root_binary_search(n, m) << endl;

    return 0;
}
