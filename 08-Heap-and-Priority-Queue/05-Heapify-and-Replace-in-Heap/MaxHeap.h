#include "Array.h"
#include <vector>

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
    int leftChild(int index) { return index * 2 + 1; }
    int rightChild(int index) { return index * 2 + 2; }

    //replace
    T replace(T e)
    {
        T ret = findMax();
        data->set(0, e);
        siftDown(0);
    }

    //Heapify

public:
    MaxHeap(int capacity) { data = new Array<T>(capacity); }
    MaxHeap() { data = new Array<T>(); }

    MaxHeap(T arr[], int n)
    {
        data = new Array<T>(arr, n);
        for (int i = parent(n - 1); i >= 0; --i)
        {
            siftDown(i);
        }
    }

    // MaxHeap(T arr[], int n)
    // {
    //     data = new Array<T>(arr, n);
    //     for (int i = parent(n - 1); i >= 0; --i)
    //     {
    //         siftDown(i);
    //     }
    // }

    int getSize() { return data->getSize(); }
    bool isEmpty() { return data->getSize() == 0; }

    void add(T e)
    {
        data->addLast(e);
    }

    T findMax()
    {
        if (data->getSize() == 0)
            assert("can not find max when heap is empty ");
        return data->get(0);
    }
    // 取出堆中最大元素
    T extractMax()
    {
        T ret = findMax();
        data->swap(0, data->getSize() - 1);
        data->removeLast();
        return ret;
    }

    void siftUp(int k)
    {
        while (k > 0 && data->get(parent(k)) < data->get(k))
        {
            data->swap(k, parent(k));
            k = parent(k);
        }
    }

    void siftDown(int k)
    {
        while (leftChild(k) < data->getSize())
        {
            int j = leftChild(k);
            if (j + 1 < data->getSize() && data->get(j + 1) > data->get(j))
                j = rightChild(k);
            // data[j] is max value between leftchild and rightchild

            if (data->get(k) > data->get(j))
                break;

            data->swap(k, j);
            k = j;
        }
    }
};
