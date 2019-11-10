#include "common.h"


//��Ϊһ��ֻ�ܷ�һ��queen������û�м���е����
bool is_valid_queen(vector<string> &queens, int row, int col)
{
    //��������Ƿ����queen
    for (int i = 0; i < row; i++)
    {
        if (queens[i][col] == 'Q')
        {
            return false;
        }
        
    }
    //������Ϸ��Ƿ���queen
    for (int i = row - 1,j = col - 1; i >= 0 && j >= 0; --i,--j)
    {
        if (queens[i][j] == 'Q')
        {
            return false;
        }

    }
    //������Ϸ��Ƿ���queen
    for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j)
    {
        if (queens[i][j] == 'Q')
        {
            return false;
        }

    }

    return true;
}

void queens_helper(int cur_row, vector<string> &queens, vector<vector<string>> &res)
{
    int n = queens.size();
    if (cur_row == n)
    {
        res.push_back(queens);
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (is_valid_queen(queens, cur_row, i))
        {
            queens[cur_row][i] = 'Q';
            queens_helper(cur_row + 1, queens, res);
            queens[cur_row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> res;
    vector<string> queens(n, string(n, '.'));
    queens_helper(0, queens, res);
    return res;
}