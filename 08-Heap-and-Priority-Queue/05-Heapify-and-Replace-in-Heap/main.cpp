#include <iostream>
#include "Array.h"
#include "MaxHeap.h"
#include <random>
#include <vector>

double testHeap(int testData[], int n, bool isHeapify)
{
    clock_t startTime = clock();

    MaxHeap<int> *maxHeap;
    if (isHeapify)
        maxHeap = new MaxHeap<int>(testData, n);
    else
    {
        maxHeap = new MaxHeap<int>();
        for (int i = 0; i < n; i++)
            maxHeap->add(testData[i]);
    }
    int arr[10];

    for (int i = 0; i < n; i++)
        arr[i] = maxHeap->extractMax();

    for (int i = 1; i < n; i++)
        if (arr[i - 1] < arr[i])
            assert("error");
    
    std::cout << "test maxheap completed\n";

    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 1000);

    Array<int> array;
    for (int i = 0; i < 10; i++)
    {
        array.addLast(i);
    }
    MaxHeap<int> maxHeap;
    const int n = 100;

    int testdata[n];
    for (int i = 0; i < n; i++)
    {
        maxHeap.add(u(e));
    }
    double time1 = testHeap(testdata, n, false);
    std::cout << "Withou heapify: " << time1 << " \n";

    // double time2 = testHeap(testdata, n, true);

    // std::cout << "Withou heapify: " << time2 << " \n";
    

    return 0;
}
