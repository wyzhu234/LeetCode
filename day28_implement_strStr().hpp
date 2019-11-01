#include "common.h"

int strStr(string haystack, string needle)
{
    if (needle == "")
    {
        return 0;
    }

    if (haystack.empty() || haystack.size() <needle.size())
    {
        return -1;
    }

    int res = 0;
    for (size_t i = 0; ; i++)
    {
        for (size_t j = 0; ; j++)
        {
            if (j == needle.size())
            {
                return i;
            }
            if (i + j == haystack.size())
            {
                return -1;
            }
            //��һ������Ҫ����Ҫ�ع����ϴ������ʵ��Ӧ��Ӧ�û���KMP�㷨�����ٻع�����
            if (needle[j] != haystack[i + j])
            {
                break;
            }
        }
    }
    return -1;
}