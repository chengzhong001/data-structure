#include <iostream>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    /* code */
    LinkedList<int> linklist =  LinkedList<int>();
    for (int i = 0; i < 5; i++)
    {
        linklist.addFirst(i);
    }
    linklist.add(2, 666);
    std::cout << linklist.toString() << std::endl;
    return 0;
}
