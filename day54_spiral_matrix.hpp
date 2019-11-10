#include "common.h"

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return{};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res;
    int up = 0;
    int down = m - 1;
    int left = 0;
    int right = n - 1;
    while (true)
    {
        for (int j = left; j <= right; j++)
        {
            res.push_back(matrix[up][j]);
        }
        if (++up > down)
        {
            break;
        }

        for (int j = up; j <= down; j++)
        {
            res.push_back(matrix[j][right]);
        }
        if (--right < left)
        {
            break;
        }

        for (int j = right; j >= left; --j)
        {
            res.push_back(matrix[down][j]);
        }
        if (--down < up)
        {
            break;
        }

        for (int j = down; j >= up; j++)
        {
            res.push_back(matrix[j][left]);
        }
        if (++left > right)
        {
            break;
        }
    }

    return res;
}

vector<int> spiralOrder_1(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return{};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res;
    int idx = 0;
    int i = 0;
    int j = 0;
    vector<vector<int>> dirs = { {0,1},{1,0},{0,-1},{-1,0} };
    for (int  k = 0; k < m * n; k++)
    {
        res.push_back(matrix[i][j]);
        matrix[i][j] = 0;
        int x = i + dirs[idx][0];
        int y = j + dirs[idx][1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 0)
        {
            idx = (idx + 1) % 4;
            x = i + dirs[idx][0];
            y = j + dirs[idx][1];
        }
        i = x;
        j = y;
    }

    return res;
}