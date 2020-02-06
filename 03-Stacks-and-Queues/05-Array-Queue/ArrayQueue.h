/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 07:49:09
 */
#include <iostream>
#include "Array.h"
#include "Queue.h"

template <class T>
class ArrayQueue : public Queue<T> {
   private:
    /* data */
    Array<T>* queue;

   public:
    ArrayQueue(int capacity) { queue = new Array<T>(capacity); };

    ArrayQueue() { queue = new Array<T>(10); };

    ~ArrayQueue() {
        delete queue;
        queue = nullptr;
    };

    int getSize() { return queue->getSize(); }

    bool isEmpty() { return queue->isEmpty(); }

    void enqueue(T e) { queue->addLast(e); }

    T dequeue() { return queue->removeFirst(); }

    T getFront() { return queue->getFirst(); }

    void print(){
        std::cout << "Queue: front [";
        for (int i = 0; i < queue->getSize(); i++)
        {
            std::cout << queue->get(i);
            if ( i != queue->getSize()-1)
            {
                std::cout << ", ";
            }
            
        }
        std::cout << "] tail" << std::endl;
    }
};
