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
        //��ײָ��
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

