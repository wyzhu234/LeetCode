#include "common.h"



void generateParentthesis_DFS(int left, int right, string out, vector<string>&res)
{
    if (left > right) return;
    if (left == 0 && right == 0)
    {
        res.emplace_back(out);
    }
    else
    {
        if (left > 0)
        {
            generateParentthesis_DFS(left - 1, right, out + '(', res);
        }
        if (right > 0)
        {
            generateParentthesis_DFS(left, right - 1, out + ')', res);
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string>res;
    generateParentthesis_DFS(n, n, "", res);
    return res;
}

vector<string> generateParenthesis_1(int n)
{
    unordered_set<string> st;
    if (n == 0)
    {
        st.insert("");
    }
    else
    {
        vector<string> pre = generateParenthesis_1(n - 1);
        for (auto a : pre)
        {
            for (size_t i = 0; i < a.size(); i++)
            {
                if (a[i] == '(')
                {
                    a.insert(a.begin() + i + 1, '(');
                    a.insert(a.begin() + i + 2, ')');
                    st.insert(a);
                    a.erase(a.begin() + i + 1, a.begin() + i + 3);
                }
            }
            st.insert("()" + a);
        }
    }

    return vector<string>(st.begin(), st.end());
}

void test_day22()
{
    vector<string> res = generateParenthesis_1(3);
}