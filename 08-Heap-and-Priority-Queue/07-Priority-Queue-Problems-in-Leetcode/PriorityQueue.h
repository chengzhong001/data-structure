#include "Queue.h"
#include "MaxHeap.h"

template <typename>
class PriorityQueue : public Queue
{
private:
    MaxHeap<T> *maxHeap;

public:
    PriorityQueue() { maxHeap = new MaxHeap<T>(); }
    int getSize() { return maxHeap->getSize(); }
    bool isEmpty() { return maxHeap->isEmpty(;) }
    T getFront() { return maxHeap->findMax(); }
    void enqueue(T e) { maxHeap->add(e); }
    T dequeue() { maxHeap->extractMax(); }
};
