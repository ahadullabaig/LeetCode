#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    int n = intervals.size();

    int i = 0;

    while(i < n)
    {
        vector<int> interval = intervals[i];

        i++;

        while(i < n)
        {
            if(intervals[i][0] <= interval[1])
            {
                interval[1] = max(interval[1], intervals[i][1]);
                i++;
            }

            else break;
        }

        merged.push_back(interval);
    }

    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> merged = merge(intervals);

    for(auto interval : merged)
    {
        for(int x : interval) cout << x << " ";

        cout << endl;
    }

    return 0;
}
