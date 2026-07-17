#include <bits/stdc++.h>

using namespace std;

bool bf_prime(int n)
{
    if(n <= 1 || (n%2 == 0 && n != 2)) return false;

    int c = 0;

    for(int i=1; i<=n; i+=2)
    {
        if(n%i == 0) c++;
    }

    return c == 2;
}

bool op_prime(int n)
{
    if(n <= 1 || (n%2 == 0 && n != 2)) return false;

    if(n == 2) return true;

    for(int i=3; (i*i) <= n; i+=2)
    {
        if(n%i == 0) return false;
    }

    return true;
}

int main()
{
    int n = 17;

    cout << op_prime(n) << endl;

    return 0;
}
