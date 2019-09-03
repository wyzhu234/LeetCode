#include "common.h"

int length_of_longgest_substring(string &s)
{
    if (s.empty())
    {
        return 0;
    }

    int res = 0;
    int left = -1;
    int n = s.size();
    unordered_map<char, int> m;
    for (size_t i = 0; i < n; i++)
    {
        if (m.count(s[i]) && m[s[i]] > left)
        {
            left = m[s[i]];
        }

        m[s[i]] = i;
        res = (std::max)(res, static_cast<int>(i - left));
    }
    return res;
}