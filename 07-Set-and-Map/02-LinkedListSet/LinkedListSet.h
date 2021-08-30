#include "Set.h"
#include "LinkedList.h"

template <typename T>
class LinkedListSet : public Set<T>
{
public:
    LinkedListSet()
    {
        list = new LinkedList<T>();
    }
    int getSize() { return list->getSize(); }

    bool isEmpty() { return list->isEmpty(); }

    bool contains(T e) { return list->contain(e); }

    void add(T e)
    {
        if (!list->contain(e))
            list->addFirst(e);
    }
    void remove(T e){
        list->remove(e);
    }

private:
    LinkedList<T> *list;
};