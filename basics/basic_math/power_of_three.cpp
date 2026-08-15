#include <bits/stdc++.h>

using namespace std;

bool isPowerOfThree(int n)
{
    if(n <= 0)
    {
        return false;
    }
    else if(n == 1)
    {
        return true;
    }
    else
    {
        return (n % 3 == 0) ? isPowerOfThree(n/3) : false;
    }
}

int main()
{
    int n = 27;

    cout << isPowerOfThree(n) << endl;

    return 0;
}
