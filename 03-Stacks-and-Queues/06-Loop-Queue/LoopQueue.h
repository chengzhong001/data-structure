/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 08:41:52
 */
#include <iostream>
#include "Queue.h"
#include <cassert>

template <class T>
class LoopQueue : public Queue<T> {
   private:
    T* data;
    int front, tail;
    int capacity;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity + 1];
        for (int i = 0; i < getSize(); i++) {
            newData[i] = data[(i + front) % capacity];
        }
        data = newData;
        tail = getSize();
        front = 0;
        capacity = newCapacity;
    }

   public:
    LoopQueue(int capacity) {
        data = new T[capacity];
        front = 0;
        tail = 0;
        this->capacity = capacity;
    }
    LoopQueue() {
        data = new T[10];
        front = 0;
        tail = 0;
        this->capacity = 10;
    }
    ~LoopQueue() {
        delete[] data;
        data = nullptr;
    };

    int getCapacity() { return capacity; }

    bool isEmpty() { return front == tail; }

    int getSize() { return (tail + capacity - front) % capacity; }

    void enqueue(T e) {
        if ((tail + 1) % capacity == front) {
            resize(capacity * 2);
        }
        data[tail] = e;
        tail = (tail + 1) % capacity;
    }

    T dequeue(){
        assert(front != tail);
        T ret = data[front];
        front = (front + 1) % capacity;
        if(getSize() == capacity / 4 && capacity / 2 != 0){
            resize(capacity / 2);
        }
        return ret;
    }

    T getFront() {
        assert(front != tail);
        return data[front];
    }

    void print(){
        std::cout << "Queue: size = " << getSize() << ", capacity = " << capacity << std::endl;
        std::cout << "front [";
        for (int i = front; i != tail; i = (i + 1) % capacity) {
            std::cout << data[i];
            if ((i + 1) % capacity != tail) {
                std::cout << ", ";
            }
        }
        std::cout << "] tail" << std::endl;
    }
};
