#include <bits/stdc++.h>

using namespace std;

vector<int> union_of_arrs(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> arr;

    int n = arr1.size(), m = arr2.size();

    int i=0, j=0;

    while(i<n && j<m)
    {
        if(arr1[i] <= arr2[j])
        {
            if(arr.empty() || arr1[i] != arr.back())
                arr.push_back(arr1[i]);

            i++;
        }
        else
        {
            if(arr.empty() || arr2[j] != arr.back())
                arr.push_back(arr2[j]);
            
            j++;
        }
    }

    while(i < n)
    {
        if(arr.empty() || arr1[i] != arr.back())
            arr.push_back(arr1[i]);

        i++;
    }

    while(j < m)
    {
        if(arr.empty() || arr2[j] != arr.back())
            arr.push_back(arr2[j]);

        j++;
    }

    return arr;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 4, 5, 6, 7};

    vector<int> arr = union_of_arrs(arr1, arr2);

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
