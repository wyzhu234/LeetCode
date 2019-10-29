#include "common.h"


void letter_combinations_dfs(string &digits,
    vector<string> &dict,
    int level,
    string out,
    vector<string> &res)
{
    if (level == digits.size())
    {
        res.emplace_back(out);
        return;
    }

    string str = dict[digits[level] - '0'];
    for (size_t i = 0; i < str.size(); i++)
    {
        letter_combinations_dfs(digits, dict, level + 1, out + str[i], res);
    }
}

vector<string> letter_combinations(string digits)
{
    if (digits.empty())
    {
        return{};
    }

    vector<string> res;
    vector<string> dict = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    letter_combinations_dfs(digits, dict, 0, "", res);
    return res;
}



vector<string> letter_combinations1(string digits)
{
    if (digits.empty())
    {
        return{};
    }

    vector<string> res = { "" };
    vector<string> dict = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    for (size_t i = 0; i < digits.size(); i++)
    {
        vector<string>temp;
        string str = dict[digits[i] - '0'];
        for (size_t j = 0; j < str.size(); j++)
        {
            //vector<string>::iterator it = res.begin();
            //for (; it != res.end(); ++it)
            //{
            //    temp.emplace_back(*it + str[j]);
            //}
            //for (string s : res)
            //{
            //    temp.emplace_back(s + str[j]);
            //}
            char c = str[j];
            for_each(res.begin(), res.end(), [&temp, c](string s) {temp.emplace_back(s + c); });
        }
        res = temp;

    }
    return res;
}