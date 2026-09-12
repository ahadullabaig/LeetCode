#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n)
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

int main()
{
    double x = 2.2121;

    int n = 2;

    cout << myPow(x, n) << endl;

    return 0;
}
