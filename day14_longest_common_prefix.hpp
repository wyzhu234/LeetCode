#include "common.h"

string longest_common_prefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }

    if (strs.size() == 1)
    {
        return strs[0];
    }

    for (size_t j = 0; j < strs[0].size(); j++)
    {
        for (size_t i = 1; i < strs.size(); i++)
        {
            if (j >= strs[i].size() || strs[i][j] != strs[0][j])
            {
                return strs[i].substr(0, j);
            }
        }
    }

}