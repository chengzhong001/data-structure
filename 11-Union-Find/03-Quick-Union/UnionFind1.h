#ifndef __UNIONFIND1__
#define __UNIONFIND1__

#include "UF.h"
#include <stdexcept>

class UnionFind1 : public UF
{
public:
    UnionFind1(int capacty)
    {
        id = new int[capacty];
        size = capacty;
        for (int i = 0; i < size; i++)
            id[i] = i;
    }
    int getSize() override { return size; }
    bool isConnected(int p, int q) override { return find(p) == find(q); }
    void unionElements(int p, int q) override
    {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID)
            return;
        for (int i = 0; i < size; i++)
        {
            if (id[i] == pID)
                id[i] = qID;
        }
    }

    ~UnionFind1()
    {
        delete[] id;
    }

private:
    int *id;
    int size;

    int find(int p)
    {
        if (p < 0 || p >= size)
            throw std::runtime_error("p is out of bound");
        return id[p];
    }
};

#endif