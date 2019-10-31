#include "common.h"

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode* swapPairs(ListNode* head)
{
    //if (head == nullptr)
    //{
    //    return head;
    //}

    ListNode *dummy = new ListNode(-1);
    //dummy->next = head;
    //ListNode *first, *second, *cur,*temp;
    //temp = dummy;
    //first = temp->next;
    //second = first->next;
    //cur = second->next;
    //while (cur)
    //{
    //    temp->next = second;
    //    second->next = first;
    //    first->next = cur;
    //    temp = first;
    //    first = cur;
    //    second = first->next;
    //    cur = second->next;
    //}
    ListNode *pre = dummy;
    dummy->next = head;
    while (pre->next && pre->next->next)
    {
        ListNode *tmp = pre->next->next;
        pre->next->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
        pre = tmp->next;
    }

    head = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return head;
   
}