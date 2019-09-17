#include "common.h"

bool is_match_1(string s, string p)
{
    if (p.empty())
    {
        return s.empty();
    }
    if (p.size() == 1)
    {
        return (s.size() == 1 && (s[0] = p[0] || p[0] == '.'));
    }
    if (p[1] != '*')
    {
        if (s.empty())
        {
            return false;
        }
        return (s[0] == p[0] || p[0] == '.') && is_match_1(s.substr(1), p.substr(1));
    }
    else
    {
        while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
        {
            if (is_match_1(s, p.substr(2)))
            {
                return true;
            }
            s = s.substr(1);
        }
    }

    return is_match_1(s, p.substr(2));
}

bool is_match_2(string s, string p)
{
    if (p.empty())
    {
        return s.empty();
    }
    if (p.size() > 1 && p[1] == '*')
    {
        return is_match_2(s, p.substr(2)) 
            || (!s.empty() && (s[0] == p[0] || p[0] == '.') && is_match_2(s.substr(1), p));
    }
    else 
    {
        return !s.empty() && (s[0] == p[0] || p[0] == '.') && is_match_2(s.substr(1), p.substr(1));
    }
}

bool is_match(string s, string p)
{
    return is_match_2(s, p);
}

void test_day10()
{
    string s = "ab";
    string p = ".*c";
    cout << is_match(s, p) << endl;
}