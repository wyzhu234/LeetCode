#include "common.h"
#include "limits"

int find_Kth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
{
    if (i >= nums1.size())
    {
        return nums2[j + k - 1];
    }

    if (j >= nums2.size() )
    {
        return nums1[i + k - 1];
    }

    if (k == 1)
    {
        return std::min(nums1[i], nums2[j]);
    }

    int  mid_val1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int  mid_val2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    if (mid_val1 < mid_val2)
    {
        return find_Kth(nums1, i + k / 2, nums2, j, k - k / 2);
    }
    else
    {
        return find_Kth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
}

double find_median_sorted_arrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int left = (m + n + 1) / 2;
    int right = (m + n + 2) / 2;
    return (find_Kth(nums1, 0, nums2, 0, left) + find_Kth(nums1, 0, nums2, 0, right)) / 2.0;
}

void test_day4()
{
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 3,4 };
    cout << find_median_sorted_arrays(nums1, nums2) << endl;
}