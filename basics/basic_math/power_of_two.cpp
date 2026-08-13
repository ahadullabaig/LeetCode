#include <bits/stdc++.h>

using namespace std;

bool my_isPowerOfTwo(int n) // floating point error for 536870912
{
    if(n <= 0) return false;

    double result = log(n)/log(2);

    return floor(result) == result;
}

bool better_isPowerOfTwo(int n) // floating point handling
{
    if(n <= 0) return false;

    double result = log(n)/log(2);

    return abs(result - round(result)) < 1e-10;
}

int main()
{
    int n = 536870912;

    cout << better_isPowerOfTwo(n) << endl;

    return 0;
}
