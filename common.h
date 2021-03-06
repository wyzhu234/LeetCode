#pragma once
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>

#include <functional>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
    static void print_list(ListNode *list_node)
    {
        while (list_node)
        {
            cout << list_node->val << " ";
            list_node = list_node->next;
        }
        cout << endl;
    }
};