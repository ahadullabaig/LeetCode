#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n)
{
    unordered_set<int> seen;

    while(n != 1)
    {
        int sum = 0;

        while(n > 0)
        {
            sum += pow(n % 10, 2);

            n /= 10;
        }

        if(seen.contains(sum)) return false;

        seen.insert(sum);

        n = sum;
    }

    return true;
}

int main()
{
    int n = 19;

    if(isHappy(n)) cout << "Happy Number" << endl;

    else cout << "Not a Happy Number" << endl;

    return 0;
}
