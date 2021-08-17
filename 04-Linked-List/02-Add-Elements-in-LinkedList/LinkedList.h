//
// Created by hpf on 18-5-8.
//

template<class T>
class Node {
public:
    T e;
    Node *next;

    Node(T e, Node *next) : e(e), next(next) {
    }

    Node(T e) : e(e), next(nullptr) {
    }

    Node() : e(), next(nullptr){
    }
};

template<class T>
class LinkedList {
private:
    Node<T> *head;
    int size;
public:
    class Range {
    };

    class Empty {
    };

    LinkedList() {
        head = nullptr;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }


    void addFirst(T e) {
        // Node<T> node = new Node<T>(e);
        // node.next = head;
        // head = node
        head = new Node<T>(e, head);
        size++;
    }

    void addLast(T e) {
        add(size, e);
    }

};
