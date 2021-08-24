#include "ListNode.h"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // while (head != nullptr && head->val == val)
        // {
        //     head = head->next;
        // }
        // if (head == nullptr)
        //     return nullptr;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *prev = dummyHead;
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }

        return dummyHead->next;
    }
};
