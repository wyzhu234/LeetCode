#include "common.h"

//typedef struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//} ListNode;

//这里返回头部
ListNode* reverse_nodes(ListNode* head)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = head;
    while (cur && cur->next)
    {
        ListNode *temp = cur->next;
        cur->next = temp->next;
        temp->next = dummy->next;
        dummy->next = temp;
    }

    head = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return head;
}

//这里返回尾部
ListNode *reverse_one_group(ListNode *pre, ListNode*next)
{
    ListNode *last = pre->next, *cur = last->next;
    while (cur != next)
    {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
    if (!head || k < 1)
    {
        return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = head;
    for (int i = 1; cur; i++)
    {
        if (i %k == 0)
        {
            pre = reverse_one_group(pre, cur->next);
            cur = pre->next;
        }
        else
        {
            cur = cur->next;
        }
    }

    head = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return head;
}


void test_day25()
{
    ListNode *head;
    ListNode *list = new ListNode(1);
    head = list;
    list->next = new ListNode(2);
    list = list->next;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(4);
    list = list->next;
    list->next = new ListNode(5);
    list = list->next;

    head = reverseKGroup(head,4);

}