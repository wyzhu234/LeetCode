#include "common.h"

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

        if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0)
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

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector < vector<int>> res;
    vector<int> out;
    vector<int> visited(nums.size(), 0);
    permute_dfs(nums, 0, visited, out, res);
    return res;
}

vector<vector<int>> permuteUnique_1(vector<int>& nums)
{
    vector < vector<int>> res;
    vector<int> out;
    vector<int> visited(nums.size(), 0);
    sort(nums.begin(), nums.end());
    res.push_back(nums);
    while (next_permutation(nums.begin(),nums.end()))
    {
        res.push_back(nums);
    }
    return res;
}

void test_day47()
{
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> permutaions = permuteUnique(nums);
}