#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<vector<int>> temp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp[i][j] = matrix[j][i];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = temp[i][n-1-j];
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{8, 1, 2},
                                  {3, 4, 2},
                                  {1, 1, 5}};

    cout << "matrix before rotating:" << endl;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++) cout << matrix[i][j] << " ";

        cout << endl;
    }

    rotate(matrix);

    cout << "\nmatrix after rotating:" << endl;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++) cout << matrix[i][j] << " ";

        cout << endl;
    }
    
    return 0;
}
