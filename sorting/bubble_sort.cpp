#include <bits/stdc++.h>

using namespace std;

void recursive_bubble_sort(vector<int> &arr, int n)
{
    if(n == 1) return;

    bool swapped = false;

    for(int i=0; i < (n-1); i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            swapped = true;
        }
    }

    if(!swapped) return;

    recursive_bubble_sort(arr, n-1);
}

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();

    for(int i=0; i < (n-1); i++)
    {
        bool swapped = false;

        for(int j=0; j < (n-1-i); j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};

    int n = arr.size();

    recursive_bubble_sort(arr, n);

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
