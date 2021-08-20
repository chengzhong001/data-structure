#include "Queue.h"
#include <assert.h>
#include <string>

template <typename T>
class Node
{
public:
    T e;
    Node<T> *next;
    Node(T e, Node *next) : e(e), next(next) {}
    Node(T e) : e(e), next(nullptr) {}
    Node() : e(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedListQueue : public Queue<T>
{
public:
    /* data */

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    void enqueue(T e)
    {
        if (tail == nullptr)
        {
            tail = new Node<T>(e);
            head = tail;
        }
        else
        {
            tail->next = new Node<T>(e);
            tail = tail->next;
        }
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
            assert("LinkedListQueue is empty");
        Node<T> *retNode = head;
        head = head->next;
        retNode->next = nullptr;
        size--;
        return retNode->e;
    }

    T getFront()
    {
        if (isEmpty())
            assert("LinkedListQueue is empty");
        return head->e;
    }

    std::string toString()
    {
        std::string res = "Queue: front ";
        Node<T> *cur = head;
        while (cur != nullptr)
        {
            res += std::to_string(cur->e) + "->";
            cur = cur->next;
        }
        res += "NULL tail";
        return res;
    }

private:
    int size;
    Node<T> *head;
    Node<T> *tail;
};
