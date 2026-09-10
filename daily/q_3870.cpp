#include <bits/stdc++.h>

using namespace std;

int countCommas(int n)
{
    int len = to_string(n).size();

    if(len <= 3) return 0;

    int count = 0, commas = 1;

    int power_of_10 = 1000;

    for(int i=4; i<len; i++)
    {
        count += power_of_10 * commas * 9;

        if(i%3 == 0) commas++;

        power_of_10 *= 10;
    }

    int first_len_num = power_of_10;

    count += (n - first_len_num + 1) * commas;

    return count;
}

int main()
{
    int n = 999999;

    cout << countCommas(n) << endl;

    return 0;
}
