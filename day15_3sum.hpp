#include "common.h"

vector<vector<int>> three_sum(vector<int> &nums)
{
    vector<vector<int> >res;
    sort(nums.begin(), nums.end());
    if (nums.empty() || nums.front() > 0 || nums.back() < 0)
        return{};

    for (int i = 0; i < nums.size(); i++) {
        int fix = nums[i];
        if (fix > 0)   break;
        if (i > 0 && fix == nums[i - 1])    continue;
        //¶Ô×²Ö¸Õë
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == -fix) {
                if (l == i + 1 || r == nums.size() - 1) {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++; r--;
                }
                else if (nums[l] == nums[l - 1])
                    l++;
                else if (nums[r] == nums[r + 1])
                    r--;
                else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++; r--;
                }

            }
            else if (nums[l] + nums[r] < -fix)
                l++;
            else
                r--;
        }
    }
    return res;
}

vector<vector<int>> n_sum_target(vector<int> &nums, int n, int start, int target)
{
    int len = nums.size();
    vector<vector<int>> res;
    if (n < 2 || len < n)
    {
        return res;
    }

    if (n == 2)
    {
        int lo = start, hi = nums.size() - 1;
        while (lo < hi)
        {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum > target)
            {
                while (lo < hi && nums[hi] == right) --hi;
            }
            else if (sum < target)
            {
                while (lo < hi && nums[lo] == left) ++lo;
            }
            else
            {
                res.push_back({ nums[lo], nums[hi] });
                while (lo < hi && nums[lo] == left) ++lo;
                while (lo < hi && nums[hi] == right) --hi;
            }
        }
    }
    else
    {
        for (int i = start; i < len; ++i)
        {
            vector<vector<int>> temp = n_sum_target(nums, n - 1, i + 1, target - nums[i]);
            for (vector<int> &vec : temp)
            {
                vec.push_back(nums[i]);
                res.push_back(vec);
            }

            while (i < len - 1 && nums[i] == nums[i + 1]) ++i;
        }
    }

    return res;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.empty() || nums.size() < 3) return vector<vector<int>>();
    sort(nums.begin(), nums.end());
    return n_sum_target(nums, 3, 0, 0);
}

void test_day15()
{
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    cout << threeSum(nums).size();
}

