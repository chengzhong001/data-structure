#include <iostream>
#include "Array.h"
#include "MaxHeap.h"
#include <random>
int main(int argc, char const *argv[])
{
    /* code */
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 100);
    
    Array<int> array;
    for (int i = 0; i < 10; i++)
    {
        array.addLast(i);
    }
    MaxHeap<int> maxHeap;
    const int n = 1000000;

    for (int i = 0; i < n; i++)
    {
        maxHeap.add(u(e));
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        arr[i] =  maxHeap.extractMax();
    }
    
    // std::cout << array.toString() << std::endl;;

    for (int i = 1; i < n; i++)
    {
        if(arr[i-1] < arr[i]){
            assert("error");
        }

    }
    std::cout << "test maxheap completed\n";
    
    
    return 0;
}
