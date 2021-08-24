#include <iostream>
#include "Solution.h"
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    // int n = std::end(arr) - std::begin(arr);

    ListNode *head = new ListNode(arr, 7);
    std::cout << "删除前：" << head->toString() << std::endl;

    ListNode *res = Solution().removeElements(head, 6, 0);
    std::cout << "删除后：" << res->toString() << std::endl;

    return 0;
}
