#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> two_sum_1(vector<int> &nums, int target)
{
    if (nums.empty())
    {
        return vector<int>();
    }

    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int t = target - nums[i];
        if (m.count(t) && m[t] != i)
        {
            res.push_back(i);
            res.push_back(m[t]);
            break;
        }
    }
    return res;
}

vector<int> two_sum_2(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(target - nums[i]))
        {
            return{ static_cast<int>(i),m[target - nums[i]] };
        }
        m[nums[i]] = i;
    }
    return vector<int>();
}

vector<int> two_sum(vector<int> &nums, int target)
{
    return two_sum_1(nums, target);
}

void test_case()
{
    vector<int> nums= { 2,7,11,15 };
    int target = 9;
    vector<int> res = two_sum(nums, target);
    for each (auto var in res)
    {
        cout << var << " " << endl;
    }
}