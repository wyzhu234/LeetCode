#include "common.h"

bool isValidSudoku(vector<vector<char>>& board)
{
    vector<vector<bool>> row_flag(9, vector<bool>(9));
    vector<vector<bool>> col_flag(9, vector<bool>(9));
    vector<vector<bool>> cell_flag(9, vector<bool>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            //这里的数字c用来表示出现的数字0-9，同时将其映射到bool矩阵中，表示该数字是否出现过。
            //很巧妙的映射。
            int c = board[i][j] - '1';
            if (row_flag[i][c] || col_flag[c][j] || cell_flag[3 * (i / 3) + j / 3][c])
            {
                return false;
            }
            row_flag[i][c] = true;
            col_flag[c][j] = true;
            cell_flag[3 * (i / 3) + j / 3][c] = true;
        }
    }

    return true;
}