/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 08:08:08
 */
#include <iostream>
#include "ArrayQueue.h"

int main(int argc, char const *argv[])
{
    ArrayQueue<int>* queue = new ArrayQueue<int>(10);
    for (int i = 0; i < 10; i++)
    {   
        queue->enqueue(i);
        if(i%3==2){
            queue->dequeue();
        }
        queue->print();
        
    }
    return 0;
}
