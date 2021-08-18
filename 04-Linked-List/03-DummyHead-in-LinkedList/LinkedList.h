#include <assert.h>
template <typename T>
class Node
{
public:
    T e;
    Node *next;

    Node(T e, Node *next) : e(e), next(next) {}

    Node(T e) : e(e), next(nullptr) {}

    Node() : e(), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *dummyHead;
    int size;

public:
    LinkedList() { dummyHead = new Node<T>(nullptr, nullptr); }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    void add(int index, T e)
    {
        assert(index < 0 || index > size);

        Node<T> prev = dummyHead;
        for (int i = 0; i < index; i++)
            prev = prev.next;
        // Node<T> node = new Node<T>(e);
        // node.next = prev.next;
        // prev.next = node;
        prev.next = new Node<T>(e, prev.next);
        size++;
    }
    void addFirst(T e) { add(size, e); }

    void addLast(T e) { add(size, e); }
};
