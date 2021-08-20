#ifndef DATASTRUCTURE_WITH_C_LINKEDLISTSTACK_H
#define DATASTRUCTURE_WITH_C_LINKEDLISTSTACK_H

#include "Stack.h"
#include "LinkedList.h"

template <typename T>
class LinkedListStack : public Stack<T>
{
public:
    LinkedListStack() { list = new LinkedList<T>(); }
    // ~LinkedListStack(){delete list;}

    bool isEmpty() { return list->isEmpty(); }

    void push(T e) { list->addFirst(e); }

    void pop() { list->removeFirst(); }

    T peek() { return list->getFirst(); }

    std::string toString()
    {
        std::string res;
        res += "Stack: top ";
        res += list->toString();
        return res;
    }

private:
    LinkedList<T> *list;
};
#endif