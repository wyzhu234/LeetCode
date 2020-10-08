#include "common.h"

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode dummy = ListNode(), *cur = &dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    cur->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *cur = head, *slow = head, *fast = head;
    while (fast && fast->next)
    {
        cur = slow; //记住中间前一个
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cur->next = NULL;
    return merge(sortList(head), sortList(slow));
}

void print_list(ListNode *list_node)
{
    while (list_node)
    {
        cout << list_node->val << " ";
        list_node = list_node->next;
    }
    cout << endl;
}

void test_day148()
{
    ListNode *l1 = new ListNode(4);
    ListNode *cur = l1;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;

    print_list(l1);
    l1 = sortList(l1);
    print_list(l1);
}