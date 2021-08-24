#include <iostream>
#include "Solution5.h"
int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 3, 4, 6, 5};
    // int n = std::end(arr) - std::begin(arr);
    
    ListNode *head = new ListNode(arr, 6);
    std::cout << head->toString() << std::endl;
    Solution().removeElements(head, 3);
    std::cout << head->toString() << std::endl;

    return 0;
}
