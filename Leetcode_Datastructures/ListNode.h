#pragma once
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode();
    ListNode(int);
    ListNode(int, ListNode*);

    bool operator==(const ListNode&) const;

    static ListNode* GenerateListNodeFromVector(const std::vector<int>&);
};