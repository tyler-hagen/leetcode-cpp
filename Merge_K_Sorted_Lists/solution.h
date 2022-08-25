#include <vector>
#include <queue>
#include "ListNode.h"

using namespace std;




class Solution {
public:

    static bool ListNodeCompare(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {   
        bool (*b)(ListNode*,ListNode*) = ListNodeCompare;
        priority_queue<ListNode*, vector<ListNode*>, decltype(b)> pq(b); 

        // O(nlogn) where n is the total number of nodes
        for(auto i = lists.begin(); i != lists.end(); i++)
        {
            auto thisListIter = *i;
            while(thisListIter != nullptr)
            {
                pq.push(thisListIter);
                thisListIter = thisListIter->next;
            }
        }

        // O(nlogn) where n is the total number of nodes
        if(pq.empty())
            return nullptr;
        ListNode* ret = pq.top(); pq.pop();
        ListNode* iter = ret;
        while(!pq.empty())
        {
            iter->next = pq.top(); pq.pop();
            iter = iter->next;
        }
        iter->next = nullptr;
        return ret;
    }
};