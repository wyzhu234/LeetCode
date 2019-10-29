#include "common.h"
int threeSumClosest(vector<int>& nums, int target)
{
    if (nums.empty() || nums.size() < 3)
    {
        return INT_MAX;
    }

    int min_diff = INT_MAX;
    int new_diff = 0;
    int temp = 0;
    int closest = 0;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 3; i++)
    {
        const int &fix = nums[i];
        if (i > 0 && fix == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            temp = nums[i] + nums[l] + nums[r];
            if (temp == target)
            {
                return temp;
            }
            else if (temp > target)
            {
                while (l < r && nums[r] == nums[--r]);
            }
            else
            {
                while (l < r&&nums[l] == nums[++l]);
            }

            new_diff = abs(target - temp);
            if (min_diff > new_diff)
            {
                min_diff = new_diff;
                closest = temp;
            }
        }
    }

    return closest;
}