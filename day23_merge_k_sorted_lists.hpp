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

    //�������죬˵�ǲ��÷����㷨
    //ԭ�����ڣ��Ա�����������ϲ����������᲻�������������ٺϲ���һ������ʱ�����ܱ����������ࡣ
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

//������С�����ݽṹ�����Ȱ�K���������Ԫ�ؼ��붼���뵽��С���У�
//���ǻ��Զ��ź���Ȼ��ÿ��ȥ����С���Ǹ�Ԫ�ؼ������ս���������С�
//Ȼ���ȡ��Ԫ�ص���һ��Ԫ�ؼ�����У��´��ԴӶ���ȡ����С��Ԫ��
//����ͬ�Ĳ������Դ����ƣ�ֱ������û��Ԫ��
//����������Ƚϣ������㷨Ҫ���㣨LeetCode��ʾ�����
ListNode* mergeKLists_1(vector<ListNode*>& lists)
{
    auto cmp = [](ListNode *&a, ListNode *&b)
    {
        return a->val > b->val;
    };

    //������С��
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