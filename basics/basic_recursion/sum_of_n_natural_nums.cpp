#include <bits/stdc++.h>

using namespace std;

int calc(int n)
{
    if(n == 1) return 1;

    return n + calc(n-1);
}

int calc_formula(int n)
{
    return (n * (n+1)) / 2;
}

int main()
{
    int n = 5;

    cout << calc_formula(n) << endl;

    return 0;
}
