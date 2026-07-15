#include <bits/stdc++.h>

using namespace std;

int bf_count(int n)
{
    int digits = 0;

    while(n > 0)
    {
        digits++;

        n /= 10;
    }

    return digits;
}

int op_count(int n)
{
    if(n == 0) return 1;

    return log10(n)+1;
}

int main()
{
    int n = 10000000;

    cout << bf_count(n) << endl << op_count(n) << endl;

    return 0;
}
