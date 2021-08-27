#include <iostream>
#include "BST.h"
int main(int argc, char const *argv[])
{
    BST<int> *bst = new BST<int>();
    int nums[] = {5, 3, 6, 8, 4, 2};
    for(int i: nums){
        // std::cout << i << "-";
        bst->add(i);
    }
    // std::cout << "\n";
    bst->preOrder(); 
    std::cout << "\n";

    // bst->preOrderNR(); 
    // std::cout << "\n";

    bst->levelOrder();

    // bst->inOrder(); 
    // std::cout << "\n";

    // bst->postOrder(); 
    // std::cout << "\n";

    // std::cout << bst->toString() << std::endl;
    return 0;
}
