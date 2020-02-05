/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 00:56:36
 */
#include <iostream>
#include "ArrayStack.h"
int main(int argc, char const *argv[])
{
    /* code */
    ArrayStack<int>* stack = new ArrayStack<int>();
    for(int i = 0; i < 5; i++){
        stack->push(i);
        stack->print();
    }
    stack->pop();
    stack->print();

    return 0;
}
