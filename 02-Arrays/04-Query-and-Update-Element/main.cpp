/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-04 11:37:32
 */
#include <iostream>
#include "Array.h"

int main(int argc, char const *argv[])
{
    Array *array = new Array(20);
    for(int i=0; i < 10; i++){
        array->addLast(i);
    }

    array->add(1, 100);
    array->addFirst(-1);
    std::cout << array->get(11) << std::endl;
    array->print();
    std::cout << array->toString() << std::endl;;
    return 0;
}
