#include <bits/stdc++.h>

using namespace std;

bool sumGame(string num) // didn't get accepted. but first try.
{
    int n = num.length();

    string s1 = "", s2 = "";

    int q = -1;

    int sum1 = 0, sum2 = 0;

    for(int i = 0; i < n/2; i++)
    {
        s1 += num[i];

        if(q == -1 && num[i] == '?') q = i;

        if(num[i] != '?') sum1 += stoi(num[i] + string());
    }

    for(int i = n/2; i < n; i++)
    {
        s2 += num[i];

        if(q == -1 && num[i] == '?') q = i;

        if(num[i] != '?') sum2 += stoi(num[i] + string());
    }

    if(q == -1) return sum1 != sum2;

    bool turn = true;

    while(q < n)
    {
        if(turn) // alice
        {
            if(sum1 >= sum2)
            {
                num[q] = '9';

                if(q < n/2) sum1 += 9;

                else sum2 += 9;
            }

            else num[q] = '0';

            q++;

            while(q < n)
            {
                if(num[q] == '?') break;

                q++;
            }

            turn = !turn;
        }
        else // bob
        {
            if(q < n/2)
            {
                if(sum1 >= sum2) num[q] = '0';

                else
                {
                    int diff = sum2 - sum1;

                    if(diff >= 0 && diff <= 9)
                    {
                        num[q] = '0' + diff;

                        sum1 += diff;
                    }

                    else
                    {
                        num[q] = '9';

                        sum1 += 9;
                    }
                }
            }
            else
            {
                if(sum2 > sum1) return true; // alice won

                else if(sum2 == sum1) num[q] = '0';

                else
                {
                    int diff = sum1 - sum2;

                    if(diff >= 0 && diff <= 9)
                    {
                        num[q] = '0' + diff;

                        sum2 += diff;
                    }

                    else
                    {
                        num[q] = '9';

                        sum2 += 9;
                    }
                }
            }

            while(q < n)
            {
                if(num[q] == '?') break;

                q++;
            }

            turn = !turn;
        }
    }

    return sum1 != sum2;
}

bool math_sumGame(string num) // mathematical solution. O(n)
{
    int n = num.length();

    int q1 = 0, q2 = 0;

    int sum1 = 0, sum2 = 0;

    for(int i=0; i<n; i++)
    {
        if(i < n/2)
        {
            if(num[i] == '?') q1++;

            else sum1 += (num[i] - '0');
        }
        else
        {
            if(num[i] == '?') q2++;

            else sum2 += (num[i] - '0');
        }
    }

    int sum_diff = sum1 - sum2;

    int q_diff = q1 - q2;

    return ((2 * sum_diff) + (9 * q_diff)) != 0;
}

int main()
{
    string s = "?3295???";

    cout << math_sumGame(s) << endl;

    return 0;
}
