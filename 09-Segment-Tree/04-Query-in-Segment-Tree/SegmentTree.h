#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <functional>
#include <string>
#include <assert.h>

template <typename T>
class SegmentTree
{
public:
    SegmentTree(T arr[], int n, std::function<T(T, T)> function)
    {
        this->function = function;
        data = new T[n];
        size = n;
        for (int i = 0; i < n; i++)
        {
            data[i] = arr[i];
        }
        tree = new T[4 * n];
        buildSegmentTree(0, 0, size - 1);
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
            assert("index is illegal");
        return data[index];
    }

    T query(int queryL, int queryR)
    {

        if (queryL >= 0 && queryL < size && queryR >= 0 && queryR < size && queryL <= queryR)
            assert("index is illegal");

        return query(0, 0, size - 1, queryL, queryR);
    }

    std::string toString()
    {
        std::string res = "[";
        for (int i = 0; i < size * 4; i++)
        {
            if (&tree[i] != nullptr)
                res += std::to_string(tree[i]);
            else
                res += "null";
            if (i != size * 4 - 1)
                res += ", ";
        }
        res += "]";
        return res;
    }

private:
    T *data;
    T *tree;
    int size;
    std::function<T(T, T)> function;

    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    void buildSegmentTree(int treeIndex, int l, int r)
    {
        if (l == r)
        {
            tree[treeIndex] = data[l];
            return;
        }
        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);
        int mid = l + (r - l) / 2;

        buildSegmentTree(leftTreeIndex, l, mid);
        buildSegmentTree(rightTreeIndex, mid + 1, r);
        tree[treeIndex] = function(tree[leftTreeIndex], tree[rightTreeIndex]);
    }

    T query(int treeIndex, int l, int r, int queryL, int queryR)
    {
        if (l == queryL && r == queryR)
        {
            return tree[treeIndex];
        }
        int mid = l + (r - l) / 2;
        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);
        if (queryL >= mid + 1)
            return query(rightTreeIndex, mid + 1, r, queryL, queryR);
        else if (queryR <= mid)
            return query(leftTreeIndex, 0, mid, queryL, queryR);
        T leftResult = query(leftTreeIndex, 0, mid, queryL, queryR);
        T rightResult = query(rightTreeIndex, mid + 1, r, queryL, queryR);
        return function(leftResult, rightResult);
    }
};

#endif