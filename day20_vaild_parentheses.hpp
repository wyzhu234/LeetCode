#include "common.h"

bool isValid(string s)
{
    if (s.empty())
    {
        return false;
    }

    stack<char> stck;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stck.push(s[i]);
        }
        else
        {
            if (stck.empty())
            {
                return false;
            }
            if (s[i] == ')' && stck.top() != '(')
            {
                return false;
            }
            if (s[i] == ']' && stck.top() != '[')
            {
                return false;
            }
            if (s[i] == '}' && stck.top() != '}')
            {
                return false;
            }
            stck.pop();
        }
    }

    return stck.empty();
}

void test_day20()
{
    string s = "[";
    bool a = isValid(s);
    cout << boolalpha << a << endl;
}