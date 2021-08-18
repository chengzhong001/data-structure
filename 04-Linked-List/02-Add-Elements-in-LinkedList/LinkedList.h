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
    Node<T> *head;
    int size;

public:
    LinkedList() { head = nullptr; }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    void addFirst(T e)
    {
        // Node<T> node = new Node<T>(e);
        // node.next = head;
        // head = node
        head = new Node<T>(e, head);
        size++;
    }

    void add(int index, T e)
    {
        assert(index < 0 || index > size);
        if (index == 0)
            addFirst(e);
        else
        {
            Node<T> prev = head;
            for (int i = 0; i < index - 1; i++)
                prev = prev.next;
            // Node<T> node = new Node<T>(e);
            // node.next = prev.next;
            // prev.next = node;
            prev.next = new Node<T>(e, prev.next);
            size++;
        }
    }

    void addLast(T e) { add(size, e); }
};
