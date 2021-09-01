#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

#include "Map.h"
#include <string>
#include <assert.h>

template <typename K, typename V>
class Node
{
public:
    K key;
    V value;
    Node<K, V> *next;

    Node(K key, V value, Node<K, V> *node) : key(key), value(value), next(node) {}
    Node(K key) : key(key), value(), next(nullptr) {}
    Node() : key(), value(), next(nullptr) {}

    std::string toString()
    {
        return std::to_string(key) + ": " + std::to_string(value);
    }
};

template <typename K, typename V>
class LinkedListMap : Map<K, V>
{
public:
    LinkedListMap()
    {
        dummyHead = new Node<K, V>();
        size = 0;
    }

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }

    Node<K, V> *getNode(K key)
    {
        Node<K, V> *cur = dummyHead->next;
        while (cur != nullptr)
        {
            if (cur->key == key)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
    bool contains(K key)
    {
        return getNode(key) != nullptr;
    }

    V* get(K key)
    {
        Node<K, V> *node = getNode(key);
        // return node == nullptr ? nullptr : node->value;
        if (node != nullptr)
        {
            return &(node->value);
        }
        return nullptr;
    }

    void add(K key, V value)
    {
        Node<K, V> *node = getNode(key);
        if (node == nullptr)
        {
            dummyHead->next = new Node<K, V>(key, value, dummyHead->next);
            size++;
        }
        else
        {
            node->value = value;
        }
    }

    void set(K key, V newValue)
    {
        Node<K, V> *node = getNode(key);
        if (node == nullptr)
        {
            assert("key does not exist! ");
        }
        node->value = newValue;
    }

    V remove(K key)
    {
        Node<K, V> *prev = dummyHead;
        while (prev->next != nullptr)
        {
            if (prev->next->key == key)
                break;
            prev = prev->next;
        }
        if (prev->next != nullptr)
        {
            Node<K, V> *delNode = prev->next;
            prev->next = delNode->next;
            delNode->next = nullptr;
            size--;
            return delNode->value;
        }
        return nullptr;
    }

private:
    Node<K, V> *dummyHead;
    int size;
};

#endif