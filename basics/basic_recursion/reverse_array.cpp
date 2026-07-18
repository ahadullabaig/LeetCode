#include <bits/stdc++.h>

using namespace std;

void rev_arr_iter(vector<int> &arr, int n)
{
    if(n < 1) return;

    for(int i=0; i < n/2; i++) swap(arr[i], arr[n-i-1]);
}

void rev_arr_recur(vector<int> &arr, int start, int end)
{
    if(start >= end) return;

    swap(arr[start], arr[end]);

    rev_arr_recur(arr, start+1, end-1);
}

int main()
{
    vector<int> arr = {1, 2, 4, 5};

    int n = arr.size();

    rev_arr_iter(arr, n);

    for(int x : arr) cout << x << " ";

    cout << endl;

    rev_arr_recur(arr, 0, n-1);

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
