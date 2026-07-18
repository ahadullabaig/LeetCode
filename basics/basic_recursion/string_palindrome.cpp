#include <bits/stdc++.h>

using namespace std;

bool check(string s, int l, int r)
{
    if(l >= r)
        return true;
    else if(s[l] == s[r])
        return check(s, l+1, r-1);
    else
        return false;
}

bool leetcode(string s)
{
    int l = 0, r = s.size()-1;

    while(l < r)
    {
        if(!isalnum(s[l]))
        {
            l++;
            continue;
        }

        if(!isalnum(s[r]))
        {
            r--;
            continue;
        }

        if(tolower(s[l]) == tolower(s[r]))
        {
            l++; r--;
        }
        else return false;
    }

    return true;
}

int main()
{
    string s = "adda";

    cout << check(s, 0, s.size()-1) << endl;

    return 0;
}
