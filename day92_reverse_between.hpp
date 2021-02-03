#include "common.h"


//反转链表前N个结点,迭代实现
ListNode* reverseN_1(ListNode* head, int n) {
    if (!head || n <= 1)
    {
        return head;
    }

    int i = 1;
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = head;
    ListNode* next = nullptr;
    while (i <= n && head)
    {
        next = head->next;
        head->next = dummy->next;
        dummy->next = head;
        head = next;
        ++i;
    }
    temp->next = next;
    return dummy->next;
}

//反转链表前N个结点,递归实现
ListNode* successor = nullptr;
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        // 记录第 n + 1 个节点
        successor = head->next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode* last = reverseN(head->next, n - 1);
    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    return last;
}
//递归实现
ListNode* reverseBetween2(ListNode* head, int m, int n)
{
    if (head == nullptr) return head;
    if (m < 1 || m >= n) return head;
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head->next = reverseBetween2(head->next, m - 1, n - 1);
    return head;
}

// 反转以 head 为头结点的链表
ListNode* reverse_all(ListNode* head) {
    ListNode* pre, * cur, * nxt;
    pre = nullptr; cur = head; nxt = head;
    while (cur != nullptr) {
        nxt = cur->next;
        // 逐个结点反转
        cur->next = pre;
        // 更新指针位置
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}

//添加哑结点，在头部插入的方式
ListNode* reverse_all_1(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* nxt;
    while (head != nullptr) {
        nxt = head->next;
        head->next = dummy->next;
        dummy->next = head;
        head = nxt;
    }
    // 返回哑结点后面的结点
    return dummy->next;
}

//递归实现反转整个链表
ListNode* reverse_all_2(ListNode* head) {
    if (head->next == nullptr) return head;
    ListNode* last = reverse_all_2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

//迭代实现
ListNode* reverseBetween1(ListNode* head, int m, int n)
{
    if (head == nullptr) return head;
    if (m < 1 || m >= n) return head;
    ListNode* pre = nullptr, * next = nullptr;
    ListNode* cur = head;
    int pos = 1;
    while (cur)
    {
        if (pos == m - 1)
        {
            pre = cur;
        }
        if (pos == n)
        {
            next = cur->next;
            cur->next = nullptr;
            break;
        }
        cur = cur->next;
        ++pos;
    }
    ListNode* temp = pre->next;
    pre->next = reverse_all_1(pre->next);
    temp->next = next;
    return head;
}

ListNode* reverseBetween3(ListNode* head, int m, int n)
{
    if (head == nullptr) return head;
    if (m < 1 || m >= n) return head;
    ListNode* pre = head;
    ListNode* cur = head;
    int pos = 0;
    while (cur)
    {
        ++pos;
        // 小于m时，无需反转
        if (pos < m)
        {
            pre = cur;
            cur = cur->next;
            continue;
        }

        ListNode* reversed_head = pre;
        pre = nullptr;
        ListNode* next;
        //当前结点会变为尾部结点
        ListNode* tail = cur;
        // 反转链表
        while (cur && pos >= m && pos <= n)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            ++pos;
        }

        reversed_head->next = pre;
        tail->next = cur;
        break;
    }
    if (m == 1)
    {
        return pre;
    }
    return head;
}

void test_day92()
{
    ListNode* head;
    ListNode* list = new ListNode(1);
    head = list;
    list->next = new ListNode(2);
    list = list->next;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(4);
    list = list->next;
    list->next = new ListNode(5);
    list = list->next;

    //ListNode::print_list(reverse_all_2(head));
    //ListNode::print_list(reverseN_1(head,3));
    //ListNode::print_list(reverseBetween1(head, 2, 4));
    ListNode::print_list(reverseBetween3(head, 1, 3));
}