#include "common.h"

vector<int> searchRange(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    vector<int> res;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            int temp = mid - 1;
            while (temp >= left && nums[temp] == target)
            {
                --temp;
            }

            res.push_back(temp +1);
            temp = mid + 1;
            while (temp <= right && nums[temp] == target)
            {
                ++temp;
            }

            res.push_back(temp - 1);
            return res;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return{ -1,-1 };
}

vector<int> searchRange_1(vector<int>& nums, int target)
{
    int left = 0;
    //ע������û�м�1������ѭ����ʱ��Ҳû���˵Ⱥš�
    //��ָ�븳ֵʱҲû�м�1�ˡ�
    int right = nums.size();
    vector<int> res(2,-1);
    //Ѱ������ֵ
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if (right == nums.size() || nums[right] != target)
    {
        return res;
    }

    res[0] = right;
    right = nums.size();
    //Ѱ���Ҳ�
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        //ע���������˵Ⱥ�
        if (nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    res[1] = right - 1;
    return res;
}