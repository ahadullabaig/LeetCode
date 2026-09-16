#include <bits/stdc++.h>

using namespace std;

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    bool conditions = (rec2[0] < rec1[2] && rec2[1] < rec1[3]) &&
                      (rec1[0] < rec2[2] && rec1[1] < rec2[3]);

    return conditions;
}

int main()
{
    vector<int> rec1 = {2, 17, 6, 20};

    vector<int> rec2 = {3, 8, 6, 20};

    cout << isRectangleOverlap(rec1, rec2) << endl;

    return 0;
}
