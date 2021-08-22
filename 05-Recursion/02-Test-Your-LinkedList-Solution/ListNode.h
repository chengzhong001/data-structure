
#include <assert.h>
#include <string>

//Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(int arr[], int n)
    {
        if (arr == nullptr || n == 0)
            assert("linkedlist is empty");
        val = arr[0];
        ListNode *cur = this;
        for (int i = 0; i < n; i++)
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }
    std::string toString()
    {
        std::string res;
        ListNode *cur = this;
        while (cur != nullptr)
        {
            res += std::to_string(cur->val) + "->";
            cur = cur->next;
        }
        res += "NULL";
        return res;
    }
};