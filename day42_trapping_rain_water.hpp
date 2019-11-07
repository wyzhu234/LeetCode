#include "common.h"

int trap(vector<int>& height)
{
    int res =  0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right)
    {
        int mn = min(height[left], height[right]);
        if (mn == height[left])
        {
            ++left;
            while (left < right && height[left] < mn)
            {
                res += mn - height[left++];
            }
        }
        else
        {
            --right;
            while (left < right && height[right] < mn)
            {
                res += mn - height[right--];
            }
        }
    }
    
    return res;
}