#include "common.h"

vector<int> findSubstring(string s, vector<string>& words)
{
    if (s.empty() || words.empty())
    {
        return{};
    }
    
    vector<int> res;
    int n = words.size();
    int len = words[0].size();
    unordered_map<string, int> word_cnt;
    for (auto &word : words)
    {
        ++word_cnt[word];
    }
    for (int i = 0; i <= (int)s.size() - n * len; i++)
    {
        unordered_map<string, int> str_cnt;
        int j = 0;
        for ( j = 0; j < n; j++)
        {
            string t = s.substr(i + j*len, len);
            if (!word_cnt.count(t))
            {
                break;
            }

            ++str_cnt[t];
            if (str_cnt[t] > word_cnt[t])
            {
                break;
            }
        }

        if (j == n)
        {
            res.push_back(i);
        }
    }
    
    return res;
}