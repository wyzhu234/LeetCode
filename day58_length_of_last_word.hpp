#include "common.h"

int lengthOfLastWord(string s)
{
    int res = 0;
    int left = 0;
    int right = s.size() - 1;
    while (s[left] == ' ')
    {
        ++left;
    }
    while (s[right] == ' ')
    {
        --right;
    }

    for (int i = left; i <= right; i++)
    {
        if (s[i] == ' ')
        {
            res = 0;
        }
        else
        {
            ++res;
        }
    }

    return res;
}

int lengthOfLastWord_1(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            if (i != 0 && s[i-1] == ' ')
            {
                res = 1;
            }
            else
            {
                ++res;
            }
        }
    }

    return res;
}

int lengthOfLastWord_2(string s)
{
    int res = 0;
    int right = s.size() - 1;
    while (s[right] == ' ')
    {
        --right;
    }

    while (right >= 0 && s[right] != ' ')
    {
        --right;
        ++res;
    }
    return res;
}