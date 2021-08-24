#include <string>
#include "ListNode.h"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val, int depth)
    {
        std::string depthString = generateDepthString(depth);
        std::cout << depthString;
        std::cout << "Call: remove " << val << " in " << head->toString() << std::endl;
        if (head == nullptr)
            return nullptr;
        ListNode *res = removeElements(head->next, val, depth + 1);
        std::cout << depthString;
        std::cout << "After: remove " << val << " in " << head->toString() << std::endl;
        ListNode *ret;
        if (head->val == val)
            ret = res;
        else
        {
            head->next = res;
            ret = head;
        }
        std::cout << depthString;
        std::cout << "Return: " << ret->toString() << std::endl;
        return ret;
    }

    std::string generateDepthString(int depth)
    {
        std::string res;
        for (int i = 0; i < depth; i++)
            res += "--";
        return res;
    }
};