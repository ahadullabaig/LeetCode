#include <bits/stdc++.h>

using namespace std;

bool armstrong(int x)
{
    if(x == 0) return true;

    int n = log10(x) + 1;

    int sum = 0, temp = x;

    while(temp > 0)
    {
        sum += pow((temp % 10), n);

        temp /= 10;
    }

    return sum == x;
}

int main()
{
    int x = 153;

    cout << armstrong(x) << endl;

    return 0;
}
