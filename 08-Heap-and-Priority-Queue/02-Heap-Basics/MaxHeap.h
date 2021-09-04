#include "Array.h"

template <typename T>
class MaxHeap
{
private:
    Array<T> *data;
    int parent(int index)
    {
        if (index == 0)
            assert("index-0 does not have parent");
        return (index - 1) / 2;
    }
    int leftChild(int index) { return index * 2 + 1; };
    int rightChile(int index) { return index * 2 + 2; }

public:
    MaxHeap(int capacity) { data = new Array<T>(capacity); }
    MaxHeap() { data = new Array<T>(); }

    int getSize() { return data->getSize(); }
    bool isEmpty() { return data->getSize() == 0; }
};
