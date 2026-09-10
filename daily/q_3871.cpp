#include <bits/stdc++.h>

using namespace std;

long long countCommas(long long n)
{
    long long len = to_string(n).size();

    if(len <= 3) return 0;

    long long count = 0, commas = 1;

    long long power_of_10 = 1000;

    for(long long i=4; i<len; i++)
    {
        count += power_of_10 * commas * 9;

        if(i%3 == 0) commas++;

        power_of_10 *= 10;
    }

    long long first_len_num = power_of_10;

    count += (n - first_len_num + 1) * commas;

    return count;
}

int main()
{
    long long n = 999999;

    cout << countCommas(n) << endl;

    return 0;
}
