#include "common.h"

bool isMatch(string s, string p)
{
    int i = 0;
    int j = 0;
    int i_star = -1;
    int j_star = -1;
    int m = s.size();
    int n = p.size();
    while (i < m)
    {
        if (j < n && (s[i] == p[j] || p[j] == '?'))
        {
            ++i;
            ++j;
        }
        else if (j < n && p[j] == '*')
        {
            i_star = i;
            j_star = j++;
        }
        else if (i_star >= 0)
        {
            i = ++i_star;
            j = j_star + 1;
        }
        else
        {
            return false;
        }
    }

    while (j < n && p[j] == '*')
    {
        ++j;
    }

    return j == n;
}