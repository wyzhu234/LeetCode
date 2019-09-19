#include "common.h"

int max_area(vector<int> &height)
{
    if (height.empty())
    {
        return 0;
    }
    size_t res = 0;
    size_t i = 0;
    size_t j = height.size() - 1;
    while (i < j)
    {
        res = max(res, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j])
        {
            ++i;
        }
        else
        {
            --j;
        }
    }
    return res;
}