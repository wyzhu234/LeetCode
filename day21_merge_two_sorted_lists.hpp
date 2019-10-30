#include "common.h"

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 || l2)
    {
        ListNode *dumy = new ListNode(-1);
        ListNode *head = dumy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                dumy->next = l1;
                l1 = l1->next;
            }
            else if (l1->val == l2->val)
            {
                dumy->next = l1;
                l1 = l1->next;
                dumy = dumy->next;
                dumy->next = l2;
                l2 = l2->next;
            }
            else
            {
                dumy->next = l2;
                l2 = l2->next;
            }
            dumy = dumy->next;
        }

        //while (l1)
        //{
        //    dumy->next = l1;
        //    l1 = l1->next;
        //    dumy = dumy->next;
        //}
        //while (l2)
        //{
        //    dumy->next = l2;
        //    l2 = l2->next;
        //    dumy = dumy->next;
        //}

        dumy->next = l1 ? l1 : l2;
        ListNode *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    else
    {
        return nullptr;
    }
}

ListNode* mergeTwoLists_reverse(ListNode* l1, ListNode* l2)
{
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists_reverse(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists_reverse(l1, l2->next);
        return l2;
    }
}

void test_day21()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *head1 = l1;
    ListNode *head2 = l2;
    l1->next = new ListNode(2);
    l1 = l1->next;
    l1->next = new ListNode(4);
    l2->next = new ListNode(3);
    l2 = l2->next;
    l2->next = new ListNode(4);
    //mergeTwoLists(head1, head2);
    ListNode * merged_node = mergeTwoLists_reverse(head1, head2);
}