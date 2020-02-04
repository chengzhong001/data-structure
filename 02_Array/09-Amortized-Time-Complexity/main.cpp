/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-05 02:40:58
 */

#include <iostream>
#include "Array.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Array<int> *array = new Array<int>();
    for(int i=0; i < 5; i++){
        array->addLast(i);
    }
    array->add(1, 100);
    array->addFirst(-1);
    array->addFirst(-1);
    array->addFirst(-1);
    std::cout << array->get(4) << std::endl;
    array->print();
    std::cout << array->toString() << std::endl;
    std::cout << array->get(5) << std::endl;
    array->remove(3);
    array->print();
    array->removeElement(-1);
    array->addFirst(1);
    array->addFirst(1);
    array->addFirst(1);
    array->addFirst(1);
    array->print();
    array->remove(3);
    // array->remove(3);
    array->print();
    return 0;
}
