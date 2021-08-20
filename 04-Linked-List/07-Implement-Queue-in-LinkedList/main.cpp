#include "LinkedListQueue.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
#include <iostream>
#include <random>

template <typename T>
double testqueue(T queue, int optCount)
{
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 100);
    clock_t startTime = clock();
    for (int i = 0; i < optCount; i++)
        queue->enqueue(u(e));

    for (int i = 0; i < optCount; i++)
        queue->dequeue();

    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

int main(int argc, char const *argv[])
{
    /* code */
    //  LinkedListQueue<int>* queue = new LinkedListQueue<int>();
    // for (int i = 0; i < 10; i++)
    // {   
    //     queue->enqueue(i);
    //     if(i%3==2){
    //         queue->dequeue();
    //     }
    //     std::cout << queue->toString() << std::endl;
    // }
    int optCount = 100000;
    
    ArrayQueue<int>* arrayqueue = new ArrayQueue<int>();
    LoopQueue<int>* loopqueue = new LoopQueue<int>();
    LinkedListQueue<int>* linkedlistqueue = new LinkedListQueue<int>();

    std::cout << "ArrayQueue: " << testqueue(arrayqueue, optCount) << std::endl;
    std::cout << "LoopQueue: " << testqueue(loopqueue, optCount) << std::endl;
    std::cout << "LinkedListQueue: " << testqueue(linkedlistqueue, optCount) << std::endl;
    return 0;
}
