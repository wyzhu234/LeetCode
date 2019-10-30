#include "common.h"

vector<string> generateParenthesis(int n)
{
    vector<string>res;
    generateParentthesis_DFS(n, n, "", res);
    return res;
}

void generateParentthesis_DFS(int left, int right, string out, vector<string>&res)
{
    if (left > right) return;
    if (left == 0 && right == 0)
    {
        res.emplace_back(out);
    }
    else
    {
        if (left > 0)
        {
            generateParentthesis_DFS(left - 1, right, out + '(', res);
        }
        if (right > 0)
        {
            generateParentthesis_DFS(left, right - 1, out + ')', res);
        }
    }
}