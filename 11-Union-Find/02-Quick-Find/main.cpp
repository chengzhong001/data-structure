#include "UnionFind1.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    // int a[] = {1, 2, 3, 4, 8};
    // for (auto i : a)
    // {
    //     std::cout << i << " ";
    // }
     UnionFind1 uf1(10);
    std::cout << uf1.getSize();
    return 0;
}
