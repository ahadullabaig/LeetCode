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

int sum_of_squares(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += pow(n % 10, 2);

        n /= 10;
    }

    return sum;
}

bool op_isHappy(int n) // O(1) space complexity. Floyd's Cycle Detection Algorithm.
{
    int slow = n;

    int fast = sum_of_squares(n);

    while(fast != 1 && fast != slow)
    {
        slow = sum_of_squares(slow);

        fast = sum_of_squares(sum_of_squares(fast)); // always 2 steps ahead
    }

    return fast == 1;
}

int main()
{
    int n = 19;

    if(op_isHappy(n)) cout << "Happy Number" << endl;

    else cout << "Not a Happy Number" << endl;

    return 0;
}
