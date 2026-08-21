#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int columnNumber)
{
    if(columnNumber <= 26)
    {
        return static_cast<char>('A' + columnNumber - 1) + string();
    }

    else if((columnNumber % 26) == 0)
    {
        return convertToTitle((columnNumber / 26) - 1) + "Z";
    }
    
    else
    {
        return convertToTitle(columnNumber / 26) + static_cast<char>('A' + (columnNumber % 26) - 1);
    }
}

int main()
{
    int n = 1608;

    cout << convertToTitle(n) << endl;

    return 0;
}
