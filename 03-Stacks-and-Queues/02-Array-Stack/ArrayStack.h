/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 01:06:18
 */

#include "Array.h"
#include "Stack.h"
#include <iostream>

template <class T> class ArrayStack : public Stack<T> {
  private:
    Array<T> *array;

  public:
    ArrayStack(int capacity) { array = new Array<T>(capacity); }

    ArrayStack() { array = new Array<T>(); }

    ~ArrayStack() {
        delete[] array;
        array = nullptr;
    }

    int getSize() { return array->getSize(); }

    bool isEmpty() { return array->isEmpty(); }

    void push(T e) { return array->addLast(e); }

    T pop() { return array->removeLast(); }

    T peek() { return array->getLast(); }

    void print() {
        std::cout << "Stack: [";
        for (int i = 0; i < array->getSize(); i++) {
            std::cout << array->get(i);
            if (i != array->getSize() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "] Top" << std::endl;
    }
};