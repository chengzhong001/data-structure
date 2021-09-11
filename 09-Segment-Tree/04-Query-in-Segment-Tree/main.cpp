#include <iostream>
#include "SegmentTree.h"

int main()
{
    int nums[] = {-2, 0, 3, -5, 2, -1};
    SegmentTree<int> *segmentTree = new SegmentTree<int>(nums, sizeof(nums) / sizeof(int), [](int a, int b) -> int
                                                         { return a + b; });
    std::cout << segmentTree->toString() << "\n";


    int a[] = {1, 3, 4};
    int b[] = {5, 6, 7};



    return 0;
}
