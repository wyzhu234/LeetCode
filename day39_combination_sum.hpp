#include "common.h"

void combination_summ_dfs(vector<int> &candidate,
                        int target,
                        int start,
                        vector<int> &out,
                        vector<vector<int>> &res)
{
    if (target < 0)
    {
        return;
    }
    if (0 == target)
    {
        res.push_back(out);
        return;
    }
    for (int i = start; i < candidate.size(); i++)
    {
        out.push_back(candidate[i]);
        combination_summ_dfs(candidate, target - candidate[i], i, out, res);
        out.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    vector<int> out;
    combination_summ_dfs(candidates, target, 0, out, res);
    return res;
}