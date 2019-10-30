#include "common.h"


//Definition for singly-linked list.
//typedef struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//} ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (nullptr == head || n < 0)
    {
        return head;
    }
    //链表处理，一般添加一个哑结点
    ListNode *dumy_node = new ListNode(-1);
    dumy_node->next = head;

    ListNode *del_node = dumy_node;
    ListNode *iter = dumy_node;

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

        ListNode *temp = del_node->next;
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
    ListNode *head;
    ListNode *list = new ListNode(1);
    head = list;
    //list->next = new ListNode(2);
    //list = list->next;
    //list->next = new ListNode(3);
    //list = list->next;
    //list->next = new ListNode(4);
    //list = list->next;
    //list->next = new ListNode(5);
    //list = list->next;

    removeNthFromEnd(head, 1);

}