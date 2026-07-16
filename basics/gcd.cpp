#include <bits/stdc++.h>

using namespace std;

int bf_gcd(int n1, int n2)
{
    for(int i=min(n1, n2); i>=1; i--)
    {
        if(n1%i == 0 && n2%i == 0)
            return i;
    }

    return 1;
}

int op_gcd(int n1, int n2)
{
    if(n2 == 0) return n1;

    return op_gcd(n2, n1 % n2);
}

int main()
{
    int n1 = 2969855, n2 = 5252400;

    cout << op_gcd(n1, n2) << endl;

    return 0;
}
