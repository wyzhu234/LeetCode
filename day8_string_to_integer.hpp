#include "common.h"

int my_atoi(string str)
{
    if (str.empty())
    {
        return 0;
    }
    int sign = 1;
    int base = 0;
    int i = 0;
    int n = str.size();
    while (i < n && str[i] == ' ')
    {
        ++i;
    }
    if (i < n && (str[i] == '+' || str[i] == '-'))
    {
        sign = str[i++] == '+' ? 1 : -1;
    }
    while (i < n && str[i] >= '0' && str[i] <= '9')
    {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        base = base * 10 + (str[i++] - '0');
    }
    return base * sign;
}

void test_day8()
{
    string num_str = "2147483646 ";
    int num = my_atoi(num_str);
    cout << num << endl;
}