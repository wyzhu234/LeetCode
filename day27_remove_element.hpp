#include "common.h"

int removeElement(vector<int>& nums, int val)
{
    int res = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[res++] = nums[i];
        }
    }
    return res;
}

int removeElement_1(vector<int>& nums, int val)
{
    int size = nums.size();
    vector<int>::iterator it = nums.begin();
    while (it != nums.end())
    {
        if (*it == val)
        {
            it = nums.erase(it);
            --size;
        }
        else
        {
            ++it;
        }
    }

    return size;
}