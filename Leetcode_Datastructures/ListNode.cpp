#include "ListNode.h"

ListNode::ListNode() : val(0), next(nullptr) 
{

}

ListNode::ListNode(int x) : val(x), next(nullptr) 
{

}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) 
{

}

bool ListNode::operator==(const ListNode& right) const 
{
    return this->val == right.val && 
        ((this->next == nullptr && right.next == nullptr) || (this->next != nullptr && right.next != nullptr && *(this->next) == *(right.next)));
}

ListNode* ListNode::GenerateListNodeFromVector(const std::vector<int>& list)
{
    if(list.empty())
        return nullptr;
    ListNode* root = new ListNode(list[0]);
    ListNode* iter = root;
    for(auto i = std::next(list.begin()); i != list.end(); i++)
    {
        iter->next = new ListNode(*i);
        iter = iter->next;
    }
    
    return root;
}