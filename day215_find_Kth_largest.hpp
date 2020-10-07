#include "common.h"

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
        return a > b;
    });
    return nums[k - 1];
}

int partion(vector<int> &nums, int left, int right)
{
    int lo = left + 1, hi = right, privot = nums[left];
    while (lo <= hi)
    {
        if (nums[lo] < privot && nums[hi] > privot)
        {
            swap(nums[lo], nums[hi]);
            ++lo;
            --hi;
        }

        while (lo <= hi && nums[lo] >= privot) ++lo;
        while (lo <= hi && nums[hi] <= privot) --hi;
    }
    swap(nums[left], nums[hi]);
    return hi;
}

int findKthLargest_2(vector<int>& nums, int k) {
    if (nums.empty() || k > nums.size())
    {
        return  -1;
    }

    int left = 0, right = nums.size() - 1, pos;
    while (true)
    {
        pos = partion(nums, left, right);
        if (pos == k - 1)
        {
            return nums[pos];
        }
        else if (pos > k - 1)
        {
            right = pos - 1;
        }
        else
        {
            left = pos + 1;
        }
    }
}

void partial_sort(vector<int> &nums, int left, int right)
{
    if (left >= right) return;
    int pos;
    pos = partion(nums, 0, nums.size() - 1);
    partial_sort(nums, 0, pos - 1);
    partial_sort(nums, pos + 1, nums.size() - 1);
}

void quick_sort(vector<int> &nums)
{
    if (nums.empty()) return;
    partial_sort(nums, 0, nums.size() - 1);
}

void test_day215()
{
    vector<int> nums = { 3,2,1,5,6,4 };
    cout << findKthLargest_2(nums, 2);
    //quick_sort(nums);
    //for (auto num : nums)
    //{
    //    cout << num;
    //}
}