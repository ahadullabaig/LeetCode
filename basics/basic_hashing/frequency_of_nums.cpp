#include <bits/stdc++.h>

using namespace std;

void freq(vector<int> &arr)
{
    unordered_map<int, int> counts;

    for(int i=0; i<arr.size(); i++)
        counts[arr[i]]++;

    for(auto x : counts)
        cout << x.first << " : " << x.second << endl;
}

int main()
{
    vector<int> arr = {1, 2, 5, 4, 4, 4, 2, 1};

    freq(arr);

    cout << endl;

    return 0;
}
