#include <iostream>
#include "BST.h"
int main(int argc, char const *argv[])
{
    BST<int> *bst = new BST<int>();
    int nums[] = {5, 3, 6, 8, 4, 2};
    for(int i: nums){
        std::cout << i << std::endl;
    }
    return 0;
}
