#include <bits/stdc++.h>

using namespace std;

void linear_search(vector<int> &arr, int key)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == key)
        {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    linear_search(arr, 5);

    linear_search(arr, 10);
    
    return 0;
}
