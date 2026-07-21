#include <bits/stdc++.h>

using namespace std;

void recursive_insertion_sort(vector<int> &arr, int n)
{
    if(n == arr.size()) return;

    int key = arr[n];

    int j = n-1;

    while(j>=0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = key;

    recursive_insertion_sort(arr, n+1);
}

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();

    for(int i=1; i<n; i++)
    {
        int key = arr[i];

        int j = i-1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main()
{
    vector<int> arr = {6, 7, 5, 4, 3, 2, 1};

    recursive_insertion_sort(arr, 1);

    for(int x : arr) cout << x << " ";

    cout << endl;
    
    return 0;
}
