using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* leftptr = nullptr;
        ListNode* rightptr = head;
        ListNode* nextptr = nullptr;

        while(rightptr != nullptr)
        {
            nextptr = rightptr->next;
            rightptr->next = leftptr;
            leftptr = rightptr;
            rightptr = nextptr;
        }
        
        return leftptr;
    }
};