#include <bits/stdc++.h>

using namespace std;

int smallestNumber(int n, int t)
{
    for(int i=n; i <= 100; i++) // condition check is 100 cuz of constraints. else loop is unbounded.
    {
        int product = 1, temp = i;

        while(temp > 0)
        {
            product *= temp % 10;

            temp /= 10;
        }

        if(product%t == 0) return i;
    }

    return -1;
}

int main()
{
    int n = 10, t = 2;

    cout << smallestNumber(n, t) << endl;

    return 0;
}
