#include "common.h"

//typedef struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//} ListNode;

ListNode *merge_two_sorted_lists(ListNode *l1, ListNode*l2)
{
    if (l1 || l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                dummy->next = l1;
                l1 = l1->next;
            }
            else
            {
                dummy->next = l2;
                l2 = l2->next;
            }

            dummy = dummy->next;
        }

        dummy->next = l1 ? l1 : l2;
        dummy = head;
        head = head->next;
        dummy->next = nullptr;
        delete dummy;
        return head;
    }
    else
    {
        return nullptr;
    }
}


ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.empty())
    {
        return nullptr;
    }

    //if (lists.size() == 1)
    //{
    //    return lists[0];
    //}

    //ListNode *first = lists[0];

    //for (size_t i = 1; i < lists.size(); i++)
    //{
    //    first = merge_two_sorted_lists(first, lists[i]);
    //}

    //return first;

    //这样更快，说是采用分治算法
    //原因在于，对比上面的两两合并，结果链表会不断增长，导致再合并下一个链表时，可能遍历次数更多。
    int n = lists.size();
    while (n >1)
    {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; ++i)
        {
            lists[i] = merge_two_sorted_lists(lists[i], lists[i + k]);
        }
        n = k;
    }

    return lists[0];

}

//利用最小堆数据结构，首先把K个链表的首元素加入都加入到最小堆中，
//他们会自动排好序，然后每次去除最小的那个元素加入最终结果的链表中。
//然后把取出元素的下一个元素加入堆中，下次仍从堆中取出最小的元素
//做相同的操作，以此类推，直到堆中没有元素
//好像比两两比较，分治算法要慢点（LeetCode显示结果）
ListNode* mergeKLists_1(vector<ListNode*>& lists)
{
    auto cmp = [](ListNode *&a, ListNode *&b)
    {
        return a->val > b->val;
    };

    //建立最小堆
    std::priority_queue< ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
    for (auto node : lists)
    {
        if (node)
        {
            q.push(node);
        }
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *head = dummy;
    while (!q.empty())
    {
        auto node = q.top();
        q.pop();
        dummy->next = node;
        dummy = dummy->next;
        if (node->next)
        {
            q.push(node->next);
        }
    }

    dummy = head;
    head = head->next;
    dummy->next = nullptr;
    delete dummy;
    return head;
}

void test_day23()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *head1 = l1;
    ListNode *head2 = l2;
    ListNode *head3 = l3;
    l1->next = new ListNode(2);
    l1 = l1->next;
    l1->next = new ListNode(4);
    l2->next = new ListNode(3);
    l2 = l2->next;
    l2->next = new ListNode(4);
    l3->next = new ListNode(6);
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    ListNode * merged_node = mergeKLists(lists);
}