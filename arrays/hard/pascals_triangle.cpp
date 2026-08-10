#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> triangle;

    for(int i=0; i < numRows; i++)
    {
        vector<int> row;

        for(int j=0; j <= i; j++)
        {
            if(j == 0 || j == i)
            {
                row.push_back(1);
            }
            else
            {
                int left = triangle[i-1][j-1];

                int right = triangle[i-1][j];

                row.push_back(left + right);
            }
        }

        triangle.push_back(row);
    }

    return triangle;
}

int main()
{
    int n = 5;

    vector<vector<int>> triangle = generate(n);

    for(auto row : triangle)
    {
        for(int element : row) cout << element << " ";

        cout << endl;
    }

    return 0;
}
