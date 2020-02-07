/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 08:08:08
 */

#include <queue>
#include <iostream>
#include "LoopQueue.h"
#include "ArrayQueue.h"

template <typename T>
double testQueue(T* queue, int opCount) {
    clock_t startTime = clock();
    srand(66);
    for (int i = 0; i < opCount; i++) {
        queue->enqueue(rand());
    }
    for (int j = 0; j < opCount; ++j) {
        queue->dequeue();
    }

    clock_t endTime = clock();
    double interval = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    return interval;
}
template <typename T>
double testQueue2(T* queue, int opCount) {
    clock_t startTime = clock();
    srand(66);
    for (int i = 0; i < opCount; i++) {
        queue->push(rand());
    }
    for (int j = 0; j < opCount; ++j) {
        queue->pop();
    }

    clock_t endTime = clock();
    double interval = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    return interval;
}

int main(int argc, char const* argv[]) {
    // LoopQueue<int>* queue = new LoopQueue<int>(10);
    int opCount = 1000000;
    std::cout << "正在执行 ArrayQueue：" << std::endl; 
    ArrayQueue<int> *arrayQueue = new ArrayQueue<int>();
    std::cout << "ArrayQueue time: " << testQueue(arrayQueue, opCount) << " s" << std::endl;

    std::cout << "正在执行 LoopQueue：" << std::endl; 
    LoopQueue<int> *loopQueue = new LoopQueue<int>();
    std::cout << "LoopQueue time: " << testQueue(loopQueue, opCount) << " s" << std::endl;

    std::cout << "正在执行 std::queue：" << std::endl; 
    std::queue<int> * queue = new std::queue<int>();
    std::cout << "queue time: " << testQueue2(queue, opCount) << " s" << std::endl;

    return 0;
}
