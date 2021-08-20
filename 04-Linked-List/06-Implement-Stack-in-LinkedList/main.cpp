#include "LinkedListStack.h"
#include "ArrayStack.h"
#include <iostream>
#include <chrono>
#include <random>

template <typename T>
double testStack(T stack, int optCount)
{
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 100);
    clock_t startTime = clock();
    for (int i = 0; i < optCount; i++)
        stack->push(u(e));

    for (int i = 0; i < optCount; i++)
        stack->pop();

    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

template <typename T>
double testStack2(T stack, int optCount)
{
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 100);
    clock_t startTime = clock();
    for (int i = 0; i < optCount; i++)
        stack.push(u(e));

    for (int i = 0; i < optCount; i++)
        stack.pop();
    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

int main(int argc, char const *argv[])
{
    ArrayStack<int> *arraystack = new ArrayStack<int>();
    LinkedListStack<int> *linkedstack = new LinkedListStack<int>();

    ArrayStack<int> arraystack2 = ArrayStack<int>();
    LinkedListStack<int> linkedstack2 = LinkedListStack<int>();
    // for(int i = 0; i < 5; i++){
    //     stack.push(i);
    //     std::cout << stack.toString() << std::endl;
    // }
    // stack.pop();
    // std::cout << stack.toString() << std::endl;

    // return 0;
    int optCount = 10000000;
    
    std::cout << "ArrayStack: " << testStack(arraystack, optCount) << std::endl;
    std::cout << "LinkedListStack: " << testStack(linkedstack, optCount) << std::endl;
    
    std::cout << "ArrayStack: " << testStack2(arraystack2, optCount) << std::endl;
    std::cout << "LinkedListStack: " << testStack2(linkedstack2, optCount) << std::endl;


}
