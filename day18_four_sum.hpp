#include "common.h"

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    if (nums.empty() || nums.size() < 4
        || nums.front() > 0 || nums.back() < 0)
    {
        return{};
    }

    vector<vector<int>> res;
    size_t N = nums.size() - 3;
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
        {
            continue;
        }

        for (int j = i +1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            
            int fix = nums[i] + nums[j];
            int l = j + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = fix + nums[l] + nums[r];
                if (sum == target)
                {
                    res.push_back({ nums[i],nums[j],nums[l],nums[r] });
                    ++l;
                    --r;
                    while (l < r && nums[r + 1] == nums[r])
                    {
                        --r;
                    }
                    while (l < r && nums[l - 1] == nums[l])
                    {
                        ++l;
                    }
                }
                else if (sum > target)
                {
                    --r;
                    while (l < r && nums[r + 1] == nums[r])
                    {
                        --r;
                    }
                }
                else
                {
                    ++l;
                    while (l < r && nums[l - 1] == nums[l])
                    {
                        ++l;
                    }
                }
            }

        }
    }
    return res;
}

void test_day18()
{
    vector<int> nums = { 1,0,-1,0,-2,2 };
    int target = 0;
    fourSum(nums, target);
}