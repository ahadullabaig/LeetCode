#include <bits/stdc++.h>

using namespace std;

// using vector<pair<int, int>> was not required. O(n*n) space complexity. find() was also inefficient.
vector<int> my_spiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> spiral;

    vector<pair<int, int>> indices(rows * cols, {-1, -1});

    int i = 0, j = 0, count = 0;

    bool increase = true;

    while(count < (rows * cols))
    {
        if(increase)
        {
            while(j < cols && find(indices.begin(), indices.end(), make_pair(i, j)) == indices.end())
            {
                spiral.push_back(matrix[i][j]);

                indices[count].first = i;
                indices[count].second = j;
                
                j++; count++;
            }

            j--; i++;

            if(find(indices.begin(), indices.end(), make_pair(i, j)) != indices.end())
            {
                increase = false;
                continue;
            }

            while(i < rows && find(indices.begin(), indices.end(), make_pair(i, j)) == indices.end())
            {
                spiral.push_back(matrix[i][j]);

                indices[count].first = i;
                indices[count].second = j;

                i++; count++;
            }

            i--; j--;

            increase = false;
        }
        else
        {
            while(j >= 0 && find(indices.begin(), indices.end(), make_pair(i, j)) == indices.end())
            {
                spiral.push_back(matrix[i][j]);

                indices[count].first = i;
                indices[count].second = j;

                j--; count++;
            }

            j++; i--;

            if(find(indices.begin(), indices.end(), make_pair(i, j)) != indices.end())
            {
                increase = true;
                continue;
            }

            while(i >= 0 && find(indices.begin(), indices.end(), make_pair(i, j)) == indices.end())
            {
                spiral.push_back(matrix[i][j]);

                indices[count].first = i;
                indices[count].second = j;

                i--; count++;
            }

            i++; j++;

            increase = true;
        }
    }

    return spiral;
}

// using unordered_set<int> makes O(n) space complexity. contains() is efficient.
vector<int> better_spiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> spiral;

    unordered_set<int> indices;

    int i = 0, j = 0, count = 0;

    bool increase = true;

    while(count < (rows * cols))
    {
        if(increase)
        {
            while(j < cols && !indices.contains((i*cols) + j))
            {
                spiral.push_back(matrix[i][j]);

                indices.insert((i*cols) + j);
                
                j++; count++;
            }

            j--; i++;

            if(indices.contains((i*cols) + j))
            {
                increase = false;
                continue;
            }

            while(i < rows && !indices.contains((i*cols) + j))
            {
                spiral.push_back(matrix[i][j]);

                indices.insert((i*cols) + j);

                i++; count++;
            }

            i--; j--;

            increase = false;
        }
        else
        {
            while(j >= 0 && !indices.contains((i*cols) + j))
            {
                spiral.push_back(matrix[i][j]);

                indices.insert((i*cols) + j);

                j--; count++;
            }

            j++; i--;

            if(indices.contains((i*cols) + j))
            {
                increase = true;
                continue;
            }

            while(i >= 0 && !indices.contains((i*cols) + j))
            {
                spiral.push_back(matrix[i][j]);

                indices.insert((i*cols) + j);

                i--; count++;
            }

            i++; j++;

            increase = true;
        }
    }

    return spiral;
}

// use 4 pointers to represent the unvisited rectangle. O(1) space complexity.
vector<int> op_spiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> spiral;

    int left = 0, right = cols-1;

    int top = 0, bottom = rows-1;

    while(left <= right && top <= bottom)
    {
        for(int j = left; j <= right; j++) spiral.push_back(matrix[top][j]);

        top++;

        for(int i = top; i <= bottom; i++) spiral.push_back(matrix[i][right]);

        right--;

        if(top <= bottom)
        {
            for(int j = right; j >= left; j--) spiral.push_back(matrix[bottom][j]);

            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; i--) spiral.push_back(matrix[i][left]);

            left++;
        }
    }

    return spiral;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {10, 11, 12, 5},
                                  {9, 8, 7, 6}};
                      
    vector<int> spiral = op_spiralOrder(matrix);

    for(int x : spiral) cout << x << " ";

    cout << endl;

    return 0;
}
