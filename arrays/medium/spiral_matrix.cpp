#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
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

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {10, 11, 12, 5},
                                  {9, 8, 7, 6}};
                      
    vector<int> spiral = spiralOrder(matrix);

    for(int x : spiral) cout << x << " ";

    cout << endl;

    return 0;
}
