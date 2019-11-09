#include "common.h"

void permute_dfs(vector<int> &num,
                int level,
                vector<int> &visited, 
                vector<int> &out,
                vector<vector<int>> &res)
{
    if (level == num.size())
    {
        res.push_back(out);
        return;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (visited[i] == 1) 
        {
            continue;
        }

        visited[i] = 1;
        out.push_back(num[i]);
        permute_dfs(num, level + 1, visited, out, res);
        out.pop_back();
        visited[i] = 0;
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector < vector<int>> res;
    vector<int> out;
    vector<int> visited(nums.size(), 0);
    permute_dfs(nums, 0, visited, out, res);
    return res;
}

void test_day46()
{
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> permutaions = permute(nums);
}