#include "common.h"

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();
    int i = n - 2;
    int j = n - 1;
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        --i;
    }
    if (i >= 0)
    {
        while (nums[j] <= nums[i])
        {
            --j;
        }
        
        swap(nums[i], nums[j]);
    }
    
    //反转时需要加1，是因为第一个while循环退出时，i为-1.
    reverse(nums.begin() + i + 1, nums.end());
}