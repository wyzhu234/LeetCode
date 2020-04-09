#include "common.h"
string addBinary(string a, string b)
{
    if (a.empty() || b.empty())
    {
        return string();
    }

    string res = "";
    int m = a.size();
    int n = b.size();
    size_t num = m >= n ? n : m;
    if (m != n)
    {
        string tmp(std::abs(m - n), '0');
        if (m > n)
        {
            b = tmp + b;
        }
        else
        {
            a = tmp + a;
        }
    }

    int carry = 0;
    int sum = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        sum = a[i] + b[i] + carry - 2 * '0';
        carry = sum / 2;
        res.insert(res.begin(), sum % 2 + '0');
    }

    if (carry)
    {
        res.insert(res.begin(), '1');
    }

    return res;
}

string addBinary(string a, string b)
{
    if (a.empty() || b.empty())
    {
        return string();
    }

    string res = "";
    int m = a.size() - 1;
    int n = b.size() - 1;
    int p = 0;
    int q = 0;
    int sum = 0, carry = 0;
    while (m >= 0 || n >= 0)
    {
        p = m >= 0 ? a[m] - '0' : 0;
        q = n >= 0 ? b[n] - '0' : 0;
        sum = p + q + carry;
        res = to_string(sum) + res;
        carry = sum / 2;
    }

    if (carry)
    {
        res = "1" + res;
    }

    return res;
}


void test_day67()
{
    string a = "1010";
    string b = "1011";
    string res = addBinary(a, b);
    cout << res;
}

