#include "UnionFind1.h"
#include "UnionFind2.h"

#include <iostream>

template<typename T>
double testUF(T* uf, int m)
{
    clock_t start_time = clock();
    int size = uf->getSize();
    for (int i = 0; i < m; i++)
    {
        int a = rand() % size;
        int b = rand() % size;
        uf->unionElements(a, b);
    }
    for (int i = 0; i < m; i++)
    {
        int a = rand() % size;
        int b = rand() % size;
        uf->isConnected(a, b);
    }

    clock_t end_time = clock();
    return (double)(start_time - end_time) / CLOCKS_PER_SEC;
}

int main(int argc, char const *argv[])
{
    /* code */
    int size = 10000;
    int m = 10000;
    UnionFind2* uf1 = new UnionFind2(size);

    std::cout << "UnionFind1: " <<  testUF(uf1, m) << " s\n";
    return 0;
}
