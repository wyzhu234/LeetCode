#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
    if (!head)
    {
        return nullptr;
    }

    int n = 1;
    ListNode *cur = head;
    while (cur->next)
    {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n;
    for (int i = 0; i < m; i++)
    {
        cur = cur->next;
    }
    ListNode *new_head = cur->next;
    cur->next = nullptr;
    return new_head;
}