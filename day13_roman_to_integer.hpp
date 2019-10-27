#include "common.h"
int roman_to_int(string s)
{
    int res = 0;
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    for (size_t i = 0; i < s.size(); i++)
    {
        int val = m[s[i]];
        if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]])
        {
            res += val;
        }
        else
        {
            res -= val;
        }
    }
    return res;
}