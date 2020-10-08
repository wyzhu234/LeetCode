#include "common.h"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }

    ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
        //先反转两个链表，如果有交叉，则最后部分则一定相同
        if (!headA || !headB) return NULL;
        ListNode *la = reverse_list(headA);
        ListNode *lb = reverse_list(headB);
        ListNode *cur = la;
        int same_num = 0;
        while (la == lb)
        {
            ++same_num;
            cur = la;
            la = la->next;
            lb = lb->next;
        }

        headA = reverse_list(la);
        headB = reverse_list(lb);
        return same_num ? cur : NULL;
    }
    ListNode *getIntersectionNode_3(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
        }
        else {
            for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
        }
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA : NULL;
    }

    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    ListNode* reverse_list(ListNode *head)
    {
        ListNode dummy = ListNode(), *cur = &dummy, *temp;
        while (head)
        {
            temp = head->next;
            head->next = cur->next;
            cur->next = head;
            head = temp;
        }

        return dummy.next;
    }
};

void test_day160()
{
    Solution sol;
    ListNode *l1 = new ListNode(4);
    ListNode *cur = l1;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    ListNode *l2 = sol.reverse_list(l1);
    ListNode::print_list(l2);
}