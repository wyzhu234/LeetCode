#include "common.h"

int longestValidParentheses(string s)
{
    int res = 0;
    int start = 0;
    int n = s.size();
    stack<int> st;
    for (int  i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                start = i + 1;
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    res = max(res, i - start + 1);
                }
                else
                {
                    res = max(res, i - st.top());

                }
            }
        }
    }

    return res;
}