#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

template<typename T>
class Stack {
public:
    int getSize();

    bool isEmpty();

    void push(T e);

    T pop();

    T peek();
};

#endif //DATASTRUCTURE_STACK_H
