#include <bits/stdc++.h>

using namespace std;

void bf_divisors(int n)
{
    for(int i=n; i>=1; i--)
    {
        if(n%i == 0) cout << i << " ";
    }
}

void op_divisors(int n)
{
    for(int i=1; i <= sqrt(n); i++)
    {
        if(i == n/i)
        {
            cout << i;
            continue;
        }

        if(n%i == 0) cout << i << " " << n/i << " ";
    }
}

int main()
{
    int n = 36;

    bf_divisors(n);

    cout <<  endl;

    op_divisors(n);

    cout <<  endl;

    return 0;
}
