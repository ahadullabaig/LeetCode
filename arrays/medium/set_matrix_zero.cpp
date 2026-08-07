#include <bits/stdc++.h>

using namespace std;

void my_setZeroes(vector<vector<int>> &matrix) // rejected due to O(m*n) space usage
{
    int rows = matrix.size(), cols = matrix[0].size();

    vector<vector<int>> indices(rows, vector<int>(cols, 0));

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j] == 0)
            {
                indices[i][j] = 1;
            }
        }
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(indices[i][j])
            {
                for(int k=0; k<rows; k++) matrix[k][j] = 0;

                for(int k=0; k<cols; k++) matrix[i][k] = 0;
            }
        }
    }
}

void acceptable_setZeroes(vector<vector<int>> &matrix) // uses O(m+n) space
{
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> row(rows, 0);

    vector<int> col(cols, 0);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;

                col[j] = 1;
            }
        }
    }

    for(int i=0; i<rows; i++)
    {
        if(row[i])
        {
            for(int j=0; j<cols; j++) matrix[i][j] = 0;
        }
    }

    for(int j=0; j<cols; j++)
    {
        if(col[j])
        {
            for(int i=0; i<rows; i++) matrix[i][j] = 0;
        }
    }
}

void op_setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    bool first_row = false, first_col = false; // to check if first row/column originally contained any zero

    // first row zero check
    for(int j=0; j<cols; j++)
    {
        if(matrix[0][j] == 0)
        {
            first_row = true;
            break;
        }
    }

    // first column zero check
    for(int i=0; i<rows; i++)
    {
        if(matrix[i][0] == 0)
        {
            first_col = true;
            break;
        }
    }

    // use the first row and first column as marker arrays
    for(int i=1; i<rows; i++)
    {
        for(int j=1; j<cols; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // the rest is just zeroing

    for(int i=1; i<rows; i++)
    {
        for(int j=1; j<cols; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if(first_row)
    {
        for(int j=0; j<cols; j++) matrix[0][j] = 0;
    }

    if(first_col)
    {
        for(int i=0; i<rows; i++) matrix[i][0] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}};

    op_setZeroes(matrix);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++) cout << matrix[i][j] << " ";

        cout << endl;
    }
    
    return 0;
}
