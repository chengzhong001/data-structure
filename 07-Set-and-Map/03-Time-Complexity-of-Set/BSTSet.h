#ifndef SET_BSTSET_H
#define SET_BSTSET_H
#include "BST.h"
#include "Set.h"

template <typename T>
class BSTSet : public Set<T>
{
public:
    BSTSet() { bst = new BSTSETSPACE::BST<T>(); }

    int getSize() { return bst->getSize(); }

    bool isEmpty() { return bst->isEmpty(); }

    void add(T e) { bst->add(e); }

    bool contains(T e) { bst->contain(e); }

    void remove(T e) { bst->remove(e); }

private:
    BSTSETSPACE::BST<T> *bst;
};

#endif