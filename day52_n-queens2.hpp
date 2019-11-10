#include "common.h"

void queens_helper2(int n,
                    int row,
                    vector<bool> &cols,
                    vector<bool> &diag, 
                    vector<bool> &anti_diag,
                    int &res)
{
    if (row == n)
    {
        ++res;
    }

    for (int  col = 0; col < n; col++)
    {
        int diag_index = col - row + n;
        int anti_diag_index = col + row;
        if (cols[col] || diag[diag_index] || anti_diag[anti_diag_index])
        {
            continue;
        }

        cols[col] = diag[diag_index] = anti_diag[anti_diag_index] = true;
        queens_helper2(n, row + 1, cols, diag, anti_diag, res);
        cols[col] = diag[diag_index] = anti_diag[anti_diag_index] = false;
    }
}


int totalNQueens(int n)
{
    int res = 0;
    vector<bool> cols(n);
    vector<bool> diag(2 * n);
    vector<bool> anti_diag(2 * n);
    queens_helper2(n, 0, cols, diag, anti_diag, res);
    return res;
}