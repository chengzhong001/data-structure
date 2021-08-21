
// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x) {}
// };

//Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        if (head == nullptr)
            return nullptr;

        ListNode *prev = head;
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }

        return head;
    }
};
