#include "common.h"

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> res;
    unordered_map<string, int> m;
    for (string str : strs)
    {
        string t = str;
        sort(t.begin(), t.end());
        if (!m.count(t))
        {
            m[t] = res.size();
            res.push_back({});
        }

        res[m[t]].push_back(str);
    }

    return res;
}

vector<vector<string>> groupAnagrams_1(vector<string>& strs)
{
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    for (string str : strs)
    {
        vector<int> cnt(26, 0);
        string t;
        for (char c : str)
        {
            ++cnt[c - 'a'];
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
            {
                continue;
            }
            t += string(1, i + 'a') + to_string(cnt[i]);
        }
        m[t].push_back(str);
    }

    for (auto a : m)
    {
        res.push_back(a.second);
    }

    return res;
}