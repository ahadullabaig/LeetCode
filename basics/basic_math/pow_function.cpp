#include <bits/stdc++.h>

using namespace std;

double bf_myPow(double x, int n) // O(|n|)
{
    if(n == 0) return 1;

    double product = 1;

    if(n > 0)
    {
        for(int i=0; i<n; i++)
        {
            product *= x;
        }
    }
    else
    {
        for(int i=n; i<0; i++)
        {
            product *= 1/x;
        }
    }

    return product;
}

double op_myPow(double x, int n) // O(log(|n|))
{
    long long pow = n;

    if(pow < 0)
    {
        x = 1/x;
        pow = -pow;
    }

    double product = 1;

    while(pow > 0)
    {
        if(pow & 1) product *= x;

        x *= x;

        pow >>= 1;
    }

    return product;
}

int main()
{
    double x = 2.2121;

    int n = 2;

    cout << bf_myPow(x, n) << endl;

    cout << op_myPow(x, n) << endl;

    return 0;
}
