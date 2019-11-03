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

            //���������c������ʾ���ֵ�����0-9��ͬʱ����ӳ�䵽bool�����У���ʾ�������Ƿ���ֹ���
            //�������ӳ�䡣
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