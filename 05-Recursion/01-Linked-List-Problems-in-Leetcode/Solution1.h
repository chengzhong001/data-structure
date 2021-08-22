
#include "ListNode.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val)
        {
            ListNode *delNode = head;
            head = head->next;
            delNode = nullptr;
        }
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *prev = head;
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)
            {
                ListNode *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
            }
            else
            {
                prev = prev->next;
            }
        }

        return head;
    }
};