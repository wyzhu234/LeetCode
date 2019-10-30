#include "common.h"


//Definition for singly-linked list.
typedef struct ListNode11 {
    int val;
    ListNode11 *next;
    ListNode11(int x) : val(x), next(NULL) {}
} ListNode11;

ListNode11* removeNthFromEnd1(ListNode11* head, int n)
{
    if (nullptr == head || n < 0)
    {
        return head;
    }
    //链表处理，一般添加一个哑结点
    ListNode11 *dumy_node = new ListNode11(-1);
    dumy_node->next = head;

    ListNode11 *del_node = dumy_node;
    ListNode11 *iter = dumy_node;

    while (iter->next != nullptr && n)
    {
        iter = iter->next;
        --n;
    }

    if (n == 0)
    {
        while (iter->next != nullptr)
        {
            iter = iter->next;
            del_node = del_node->next;
        }

        ListNode11 *temp = del_node->next;
        del_node->next = temp->next;
        delete temp;
    }
    else
    {
        cout << "n is lager than the length of list " << endl;
    }
    head = dumy_node->next;
    delete dumy_node;
    return head;
}


void test_day19()
{
    ListNode11 *head;
    ListNode11 *list = new ListNode11(1);
    head = list;
    //list->next = new ListNode11(2);
    //list = list->next;
    //list->next = new ListNode11(3);
    //list = list->next;
    //list->next = new ListNode11(4);
    //list = list->next;
    //list->next = new ListNode11(5);
    //list = list->next;

    removeNthFromEnd1(head, 1);

}