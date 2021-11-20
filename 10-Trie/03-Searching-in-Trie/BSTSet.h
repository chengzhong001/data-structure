#include "BST.h"
#include "Set.h"

template <typename T>
class BSTSet : public BST<T>
{
public:
    BSTSet() { bst = new BST<T>(); }

    int getSize() { return bst->getSize(); }

    bool isEmpty() { return bst->isEmpty(); }

    void add(T e) { bst->add(e); }

    bool contains(T e) { return  bst->contain(e); }

    void remove(T e) { bst->remove(e); }

private:
    BST<T> *bst;
};