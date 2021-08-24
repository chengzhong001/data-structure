#include "ListNode.h"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode* res = removeElements(head->next, val);
        if(head->val == val)
            return res;
        else{
            head->next = res;
            return head;
        }

    }
};