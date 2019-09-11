#include "common.h"

void search_palindrome(string s, int left, int right, int &start, int &max_len)
{
    while (left >=0 && right <s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }

    if (max_len < right - left -1)
    {
        start = left + 1;
        max_len = right - left - 1;
    }
}

string longestPalindrome(string s)
{
    if (s.size() < 2)
    {
        return s;
    }
    
    int n = s.size();
    int max_len = 0;
    int start = 0;
    for (size_t i = 0; i < n - 1; i++)
    {
        search_palindrome(s, i, i, start, max_len);
        search_palindrome(s, i, i + 1, start, max_len);
    }
    return s.substr(start, max_len);
}

//¶¯Ì¬¹æ»®
string longestPalindrome_1(string s)
{
    if (s.empty())
    {
        return s;
    }
    const int n = s.size();
    vector<vector<int>>dp;
    int left = 0;
    int max_len = 1;
    for (size_t i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        for (size_t j = 0; j < i; j++)
        {
            dp[j][i] = (s[i] == s[j] && (i - j < 2
                || dp[j + 1][i - 1]));
            if (dp[j][i] && max_len < i -j + 1)
            {
                max_len = i - j + 1;
                left = j;
            }
        }
    }
    return s.substr(left, max_len);
}

void test_day5()
{
    string s = "abc";
    string longest = longestPalindrome(s);
    cout << longest << endl;
}