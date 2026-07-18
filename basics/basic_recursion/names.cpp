#include <bits/stdc++.h>

using namespace std;

void print(int n)
{
    if(n == 0) return;

    cout << "Ahad" << endl;

    print(n-1);
}

int main()
{
    int n = 5;

    print(n);

    return 0;
}
