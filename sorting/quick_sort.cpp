#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];

    int i = left - 1;

    for(int j=left; j<=right-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[right]);

    return i+1;
}

void quicksort(vector<int> &arr, int left, int right)
{
    if(left < right)
    {
        int pi = partition(arr, left, right);

        quicksort(arr, left, pi-1);

        quicksort(arr, pi+1, right);
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 1, 1, 1, 7, 8, 2, 3};

    quicksort(arr, 0, arr.size() - 1);

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
