/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 08:08:08
 */
#include <iostream>
#include "LoopQueue.h"

int main(int argc, char const *argv[])
{
    LoopQueue<int>* queue = new LoopQueue<int>(10);
    
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
