#include "common.h"

vector<int> searchRange(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    vector<int> res;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            int temp = mid - 1;
            while (temp >= left && nums[temp] == target)
            {
                --temp;
            }

            res.push_back(temp +1);
            temp = mid + 1;
            while (temp <= right && nums[temp] == target)
            {
                ++temp;
            }

            res.push_back(temp - 1);
            return res;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return{ -1,-1 };
}