#include "common.h"

#include <forward_list>

forward_list<int> add_two_numbers(forward_list<int> &list1, forward_list<int> &list2)
{
    forward_list<int> dumy;
    int carry = 0;
    forward_list<int>::iterator it1 = list1.begin();
    forward_list<int>::iterator it2 = list2.begin();
    forward_list<int>::iterator it_res = dumy.before_begin();
    int val1 = 0;
    int val2 = 0;
    while (it1 != list1.end() || it2!= list2.end())
    {
        if (it1 != list1.end())
        {
            val1 = *it1;
        }
        else
        {
            val1 = 0;
        }

        if (it2 != list2.end())
        {
            val2 = *it2;
        }
        else
        {
            val2 = 0;
        }
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        it_res = dumy.emplace_after(it_res, sum % 10);
        ++it1;
        ++it2;
    }
    if (carry)
    {
        dumy.emplace_after(dumy.end(), 1);
    }
    return dumy;
}

void test_day2()
{
    forward_list<int> list1 = { 2,4,3 };
    forward_list<int> list2 = { 5,6,4 };
    forward_list<int> res = add_two_numbers(list1, list2);
    for (int &x : res)
    {
        cout << x;
    }
    cout << endl;
}