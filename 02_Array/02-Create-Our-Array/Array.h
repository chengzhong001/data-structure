/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-04 12:05:13
 */

#ifndef DATASTRUCTURE_ARRAY_H
#define DATASTRUCTURE_ARRAY_H

#endif //DATASTRUCTURE_ARRAY_H
class Array {
private:
    int *data;
    int size;
    int capacity;
public:
    Array(int capacity) {
        data = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    Array() {
        data = new int[10];
        size = 0;
        capacity = 10;
    }

    int getCapacity() {
        return capacity;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};