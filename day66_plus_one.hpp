#include "common.h"
vector<int> plusOne(vector<int>& digits)
{
    if (digits.empty())
    {
        return vector<int>();
    }

    for (int i = digits.size() - 1; i >= 0; --i)
    {
        if (digits[i] != 9)
        {
            digits[i] += 1;
            return digits;
        }
        else
        {
            digits[i] = 0;
            if (i == 0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
    }
}

void test_day66()
{
    vector<int> digits = { 1,2,3 };
    auto vec = plusOne(digits);
    for (auto num : vec)
    {
        std::cout << num;
    }
}