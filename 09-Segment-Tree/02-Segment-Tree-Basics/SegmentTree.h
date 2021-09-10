#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <assert.h>
template <typename T>
class SegmentTree
{
public:
    SegmentTree(T arr[], int n)
    {
        data = new T[n];
        size = n;
        for (int i = 0; i < n; i++)
        {
            data[i] = arr[i];
        }
        tree = new T[4n];
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
            assert("index is illegal");
        return data[index];
    }

    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

private:
    T *data;
    T *tree;
    int size;
};

#endif