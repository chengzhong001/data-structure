#include "UF.h"

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

    int getSize() override { return size; }
    bool isConnected(int p, int q) override { return find(p) == find(q); }
    void unionElements(int p, int q) override
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
        while (p != parent[p])
            p = parent[p];

        return p;
    }
};
