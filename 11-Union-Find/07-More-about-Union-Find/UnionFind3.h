#ifndef __UNIONFIND3__
#define __UNIONFIND3__
#include "UF.h"
#include <stdexcept>
class UnionFind3 : public UF
{

public:
    UnionFind3(int capacity)
    {
        parent = new int[capacity];
        sz = new int[capacity];
        size = capacity;
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    ~UnionFind3() { delete[] parent; }

    virtual int getSize() override { return size; }
    virtual bool isConnected(int p, int q) override { return find(p) == find(q); }
    virtual void unionElements(int p, int q) override
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (sz[pRoot] < sz[qRoot])
        {
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        }
        else
        {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
    }

private:
    int *parent;
    int *sz;
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