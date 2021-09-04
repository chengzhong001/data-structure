#include <iostream>
#include "Array.h"
#include "MaxHeap.h"
int main(int argc, char const *argv[])
{
    /* code */
    Array<int> array;
    for (int i = 0; i < 10; i++)
    {
        array.addLast(i);
    }
    array.print();
    std::cout << array.toString() << std::endl;;
    
    return 0;
}
