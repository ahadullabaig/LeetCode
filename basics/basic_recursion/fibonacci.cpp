#include <bits/stdc++.h>

using namespace std;

void fibonacci(int n, int prev, int curr)
{
    if(n == 0) return;

    cout << prev+curr << " ";

    fibonacci(n-1, curr, prev+curr);
}

int leetcode(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int prev = 0, curr = 1;

    for(int i=2; i<=n; i++)
    {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main()
{
    int n = 10;

    cout << "0 1 ";

    fibonacci(n-2, 0, 1);

    cout << endl;

    cout << leetcode(n) << endl;

    return 0;
}
