#include <iostream>
#include "Array.h"
#include "MaxHeap.h"
// #include <random>
#include <vector>

template<typename T>
double testHeap(T testData[], int n, bool isHeapify)
{
    clock_t startTime = clock();

    MaxHeap<T>* maxHeap;
    if (isHeapify)
        maxHeap = new MaxHeap<T>(testData, n);
    else
    {
        maxHeap = new MaxHeap<T>();
        for (int i = 0; i < n; i++)
            maxHeap->add(testData[i]);
    }

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = maxHeap->extractMax();

    for (int i = 1; i < n; i++)
        if (arr[i - 1] < arr[i])
            assert("error");

    std::cout << "test maxheap completed\n";

    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double testHeap2(int testData[], int n, bool isHeapify)
{

    clock_t startTime = clock();

    MaxHeap<int> maxHeap;
    if (isHeapify)
        maxHeap = MaxHeap<int>(testData, n);
    else
    {

        for (int i = 0; i < n; i++)
            maxHeap.add(testData[i]);
    }
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = maxHeap.extractMax();

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

    const int n = 10000;

    // int testdata[n];
    int *testData = new int[n];
    for (int i = 0; i < n; ++i)
    {
        testData[i] = rand() % INT32_MAX;
        std::cout << rand() % 100 << "\n";
    }
   
    double time1 = testHeap(testData, n, true);
    std::cout << "Withou heapify: " << time1 << " \n";

    double time2 = testHeap(testData, n, false);
    std::cout << "Withou heapify: " << time2 << " \n";

    // std::cout << rand()  << "\n";

    return 0;
}
