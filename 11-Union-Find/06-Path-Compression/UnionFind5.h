#ifndef __UNIONFIND5__
#define __UNIONFIND5__
#include "UF.h"
#include <stdexcept>
class UnionFind5 : public UF
{

public:
    UnionFind5(int capacity)
    {
        parent = new int[capacity];
        rank = new int[capacity];
        size = capacity;
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind5() { delete[] parent; }

    virtual int getSize() override { return size; }
    virtual bool isConnected(int p, int q) override { return find(p) == find(q); }
    virtual void unionElements(int p, int q) override
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
        {
            return;
        }

        if (rank[pRoot] < rank[qRoot])
        {
            parent[pRoot] = qRoot;
        }
        else if (rank[pRoot] > rank[qRoot])
        {
            parent[qRoot] = pRoot;
        }
        else
        {
            parent[qRoot] = pRoot;
            rank[pRoot] += 1;
        }
    }

private:
    int *parent;
    int *rank;
    int size;
    int find(int p)
    {
        if (p < 0 || p >= size)
            throw std::runtime_error("p is out of bound");
        while (p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        //路经压缩

        return p;
    }
};

#endif