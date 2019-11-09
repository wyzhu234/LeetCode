#include "common.h"

double myPow(double x, int n)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    double res = 1;
    int index = n > 0 ? n : -n;
    while (index > 0)
    {
        res *= x;
        --index;
    }

    if (n > 0)
    {
        return res;
    }
    else
    {
        return 1.0 / res;
    }
}

double myPow_1(double x, int n)
{
    double res = 1.0;
    for (int i = n; i !=0; i /= 2)
    {
        if (i % 2)
        {
            res *= x;
        }
        x *= x;
    }
    return n > 0 ? res : 1.0 / res;
}

double myPow_2(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double half = myPow(x, n / 2);
    if (n % 2 == 0)
    {
        return half * half;
    }
    else if (n > 0 )
    {
        return half * half * x;
    }
    else
    {
        return half * half / x;
    }
}

double power(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double half = power(x, n / 2);
    if (n % 2 == 0)
    {
        return half *half;
    }
    else
    {
        return x * half * half;
    }
}

double myPow_3(double x, int n)
{
    if (n < 0)
    {
        return 1 / power(x, -n);
    }
    
    return pow(x, n);
}

void test_day50()
{
    double res = myPow(2.0, 10);
    cout << res << endl;
}