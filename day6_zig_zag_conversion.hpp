#include "common.h"

string convert_1(string s, int num_rows)
{
    if (num_rows <= 1 || s.empty())
    {
        return s;
    }

    string res;
    int size = 2 * num_rows - 2;
    int n = s.size();
    for (size_t i = 0; i < num_rows; i++)
    {
        for (size_t j = i; j < n; j += size)
        {
            res += s[j];
            int pos = j + size - 2 * i;
            if (i != 0 && i != num_rows - 1 && pos < n)
            {
                res += s[pos];
            }
        }
    }
    return res;
}

string convert_2(string s, int num_rows)
{
    if (num_rows <= 1 || s.empty())
    {
        return s;
    }
    string res;
    int i = 0;
    int n = s.size();
    vector<string> vec(num_rows);
    while (i < n)
    {
        for (size_t j = 0; j < num_rows && i < n; j++)
        {
            vec[j] += s[i++];
        }

        for (size_t j= num_rows - 2; j >= 1 && i < n; --j)
        {
            vec[j] += s[i++];
        }
    }

    for (size_t i = 0; i < vec.size(); i++)
    {
        res += vec[i];
    }
    return res;
}