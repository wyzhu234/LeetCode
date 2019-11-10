#include "common.h"

bool canJump(vector<int>& nums)
{
    int n = nums.size();
    int reach = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > reach || reach >= n-1)
        {
            break;
        }
        reach = max(reach, nums[i] + i);
    }

    return reach >= n - 1;
}
