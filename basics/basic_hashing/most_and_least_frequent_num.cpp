#include <bits/stdc++.h>

using namespace std;

void most_and_least(vector<int> &arr)
{
    unordered_map<int, int> counts;

    for(int x : arr) counts[x]++;

    int max = arr[0], min = arr[0];

    for(auto x : counts)
    {
        if(x.second > counts[max])
            max = x.first;
        
        if(x.second < counts[min])
            min = x.first;
    }

    cout << "Most Frequent: " << max << "\nLeast Frequent: " << min << endl;
}

int main()
{
    vector<int> arr = {1, 2, 2, 4, 4, 4, 2, 4};

    most_and_least(arr);

    return 0;
}
