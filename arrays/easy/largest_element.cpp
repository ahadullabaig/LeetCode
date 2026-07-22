#include <bits/stdc++.h>

using namespace std;

int largest_element(vector<int> &arr)
{
    int largest = arr[0];

    for(int x : arr)
    {
        if(x > largest) largest = x;
    }

    return largest;
}

int main()
{
    vector<int> arr = {1, 2, 10, 4, 5, 6, 9};

    cout << "Largest Element = " << largest_element(arr) << endl;

    return 0;
}
