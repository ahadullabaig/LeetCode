#include <bits/stdc++.h>

using namespace std;

int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) // O(n*log(n))
{
    sort(reservedSeats.begin(), reservedSeats.end());

    int count = 2*n; // assume best case scenario

    int seat = 0, length = reservedSeats.size();

    while(seat < length)
    {
        unordered_set<int> seats;

        int row = reservedSeats[seat][0];

        while(seat < length && reservedSeats[seat][0] == row)
        {
            seats.insert(reservedSeats[seat][1]);

            seat++;
        }

        if(seats.contains(5) && seats.contains(6)) count -= 2;

        else if(seats.contains(5))
        {
            if(!(seats.contains(6) || seats.contains(7) || seats.contains(8) || seats.contains(9))) count--;

            else count -= 2;
        }

        else if(seats.contains(6))
        {
            if(!(seats.contains(2) || seats.contains(3) || seats.contains(4) || seats.contains(5))) count--;

            else count -= 2;
        }

        else
        {
            if(!(seats.contains(2) || seats.contains(3) || seats.contains(4)) &&
                !(seats.contains(7) || seats.contains(8) || seats.contains(9)))
            {
                continue;
            }

            else if(!(seats.contains(2) || seats.contains(3) || seats.contains(4))) count--;

            else if(!(seats.contains(7) || seats.contains(8) || seats.contains(9))) count--;

            else if(!(seats.contains(4) || seats.contains(7))) count--;

            else count -= 2;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};

    int n = 3;

    cout << maxNumberOfFamilies(n, reservedSeats) << endl;

    return 0;
}
