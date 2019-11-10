#include "common.h"

int maxSubArray(vector<int>& nums)
{
    int res = INT_MIN;
    int cur_sum = 0;
    for (int num : nums)
    {
        cur_sum = max(cur_sum + num, num);
        res = max(res, cur_sum);
    }

    return res;
}

int helper_53(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return nums[left];
    }

    int mid = left + (right - left) / 2;
    int lmax = helper_53(nums, left, mid - 1);
    int rmax = helper_53(nums, mid + 1, right);
    int mmax = nums[mid];
    int t = mmax;
    for (int i = mid - 1; i >= left; --i)
    {
        t += nums[i];
        mmax = max(mmax, t);
    }

    t = mmax;
    for (int i = mid + 1; i <= right; i++)
    {
        t += nums[i];
        mmax = max(mmax, t);
    }

    return max(mmax, max(lmax, rmax));
}

int maxSubArray_1(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    return helper_53(nums, 0, static_cast<int>(nums.size() - 1));

}