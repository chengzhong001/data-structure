#ifndef __UNIONFIND2__
#define __UNIONFIND2__
#include "UF.h"
#include <stdexcept>
class UnionFind2 : public UF
{

public:
    UnionFind2(int capacity)
    {
        parent = new int[capacity];
        size = capacity;
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }
    ~UnionFind2() { delete[] parent; }

    virtual int getSize() override { return size; }
    virtual bool isConnected(int p, int q) override { return find(p) == find(q); }
    virtual void unionElements(int p, int q) override
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        parent[pRoot] = qRoot;
    }

private:
    int *parent;
    int size;
    int find(int p)
    {
        if (p < 0 || p >= size)
            throw std::runtime_error("p is out of bound");
        while (p != parent[p])
            p = parent[p];

        return p;
    }
};

#endif