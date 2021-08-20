#include <cassert>
#include <string>

template <typename T>
class Node
{
public:
    T e;
    Node<T> *next;

    Node(T e, Node *next) : e(e), next(next) {}

    Node(T e) : e(e), next(nullptr) {}

    Node() :  next(nullptr) {}

    ~Node() { delete next; }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *dummyHead;
    int size;

public:
    LinkedList()
    {
        dummyHead = new Node<T>();
        size = 0;
    }
    // ~LinkedList() { delete dummyHead; }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    void add(int index, T e)
    {

        if (index < 0 || index > size)
            assert("add failed, llega index");

        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++)
            prev = prev->next;
        // Node<T> node = new Node<T>(e);
        // node.next = prev.next;
        // prev.next = node;
        prev->next = new Node<T>(e, prev->next);
        size++;
    }
    void addFirst(T e) { add(0, e); }

    void addLast(T e) { add(size, e); }

    T get(int index)
    {
        if (index < 0 || index > size)
            assert("get failed, llega index");
        Node<T> *cur = dummyHead->next;
        for (int i = 0; i < index; i++)
            cur = cur->next;

        return cur->e;
    }
    T getFirst()
    {
        return get(0);
    }
    T getLast()
    {
        return get(size - 1);
    }

    void set(int index, T e)
    {
        if (index < 0 || index > size)
            assert("update failed, illega index");
        Node<T> *cur = dummyHead->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur->e = e;
    }

    bool contain(T e)
    {
        Node<T> *cur = dummyHead->next;
        while (cur != nullptr)
        {
            if (cur->e == e)
                return true;
            cur = cur->next;
        }
        return false;
    }

    T remove(int index)
    {
        if (index < 0 || index > size)
            assert("update failed, illega index");
        if (size == 0)
            assert("linkedlist is empty");
        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++)
            prev = prev->next;
        Node<T> *retNode = prev->next;
        prev->next = retNode->next;
        retNode->next = nullptr;
        delete retNode;
        size--;
        return retNode->e;
    }

    T removeFirst()
    {
        return remove(0);
    }

    T removeLast()
    {
        return remove(size - 1);
    }

    std::string toString()
    {
        std::string res;
        Node<T> *cur = dummyHead->next;
        while (cur != nullptr)
        {
            res += std::to_string(cur->e) + "->";
            cur = cur->next;
        }
        res += "NULL";
        return res;
    }
};
