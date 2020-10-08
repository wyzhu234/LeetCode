#include "common.h"

#include <forward_list>

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};


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

ListNode* add_two_numbers1(ListNode *list1, ListNode *list2)
{
    ListNode *dumy = new ListNode(-1);
    ListNode *res = dumy;
    int carry = 0;
    int val1 = 0;
    int val2 = 0;
    while (list1 || list2)
    {
        if (list1)
        {
            val1 = list1->val;
        }
        else
        {
            val1 = 0;
        }

        if (list2)
        {
            val2 = list2->val;
        }
        else
        {
            val2 = 0;
        }
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        dumy->next = new ListNode(sum % 10);
        dumy = dumy->next;
        if (list1)
        {
            list1 = list1->next;
        }
        if (list2)
        {
            list2 = list2->next;
        }
    }

    if (carry)
    {
        dumy->next = new ListNode(carry);
    }

    return res->next;
}
void test_day2()
{
    forward_list<int> list1 = { 2,4,3 };
    forward_list<int> list2 = { 5,6,4 };
    forward_list<int> res = add_two_numbers(list1, list2);
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *res1 = add_two_numbers1(l1, l2);
    while (res1)
    {
        cout << res1->val;
        res1 = res1->next;
    }

    //for (int &x : res)
    //{
    //    cout << x;
    //}
    cout << endl;
}