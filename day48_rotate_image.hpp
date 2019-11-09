#include "common.h"

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size() - 1;
    vector<vector<int>>temp(matrix);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            matrix[j][n-i] = matrix[i][j];
        }
    }
    temp.swap(matrix);
}

void rotate_1(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (size_t i = 0; i < n / 2; i++)
    {
        for (size_t j = i; j < n - i - 1; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tmp;
        }
    }
}

void rotate_2(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}