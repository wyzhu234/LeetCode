#include "common.h"

int searchInsert(vector<int>& nums, int target)
{
    if (nums.empty())
    {
        return 0;
    }

    if (nums.back() < target)
    {
        return nums.size();
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}