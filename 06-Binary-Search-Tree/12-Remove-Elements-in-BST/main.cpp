#include <iostream>
#include <random>
#include <vector>

#include "BST.h"
int main(int argc, char const *argv[])
{
    BST<int> *bst = new BST<int>();
    
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 100);
    const unsigned int n = 10;;
    for (int i = 0; i < n; i++)
        bst->add(u(e));

    bst->preOrder();
    bst->remove(66);

    std::vector<int> nums;
  
    while (!bst->isEmpty())
        nums.push_back(bst->removeMin());
    for(int num: nums)
        std::cout << num << " ";
    std::cout << std::endl;;

  
    
    return 0;
}
