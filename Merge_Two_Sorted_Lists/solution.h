
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    bool operator==(const ListNode& right) const 
    {
        return this->val == right.val && 
            ((this->next == nullptr && right.next == nullptr) || (this->next != nullptr && right.next != nullptr && *(this->next) == *(right.next)));
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ret;

        
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        if(list1 == nullptr)
        {
            ret = list2;
            list2 = list2->next;
            return ret;
        }
        if(list2 == nullptr)
        {
            ret = list1;
            list1 = list1->next;
            return ret;
        }

        if(list1->val <= list2->val)
        {
            ret = list1;
            list1 = list1->next;
        }
        else
        {
            ret = list2;
            list2 = list2->next;
        }

        ret->next = mergeTwoLists(list1, list2);

        return ret;
    }
};

ListNode* generateListFromVector(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    if(begin == end)
        return nullptr;
    
    ListNode* root = new ListNode(*begin);

    root->next = generateListFromVector(++begin, end);

    return root;
}

ListNode* generateListFromVector(const vector<int>& vec)
{
    return generateListFromVector(vec.begin(), vec.end());
}