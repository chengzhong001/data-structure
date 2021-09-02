
#ifndef BSTMAP_H
#define BSTMAP_H

#include <assert.h>
#include "Map.h"
template <typename K, typename V>
class Node
{
public:
    K key;
    V value;
    Node<K, V> *left;
    Node<K, V> *right;
    Node(K key, V value) : key(key), value(value), left(nullptr), right(nullptr) {}
};

template <typename K, typename V>
class BSTMap : Map<K, V>
{
public:
    BSTMap() : root(nullptr), size(0) {}
    int getSize() { return size; }
    bool isEmpty() { return size == 0; }

    void add(K key, V value)
    {
        root = add(root, key, value);
    }

    bool contains(K key)
    {
        return getNode(root, key) != nullptr;
    }

    V *get(K key)
    {
        Node<K, V> *node = getNode(root, key);
        return node == nullptr ? nullptr : &(node->value);
    }

    void set(K key, V newValue)
    {

        Node<K, V> *node = getNode(root, key);
        if (node == nullptr)
            assert("key does not exist");
        node->value = newValue;
    }

    V *remove(K key)
    {
        Node<K, V> *node = getNode(root, key);
        if (node == nullptr)
            return nullptr;
        root = remove(root, key);
        return &(node->value);
    }

private:
    Node<K, V> *root;
    int size;

    Node<K, V> *add(Node<K, V> *node, K key, V value)
    {
        if (node == nullptr)
        {
            size++;
            return new Node<K, V>(key, value);
        }
        if (key < node->key)
            node->left = add(node->left, key, value);
        else if (key > node->key)
            node->right = add(node->right, key, value);
        else
            node->value = value;

        return node;
    }

    Node<K, V> *getNode(Node<K, V> *node, K key)
    {
        if (node == nullptr)
            return nullptr;
        if (key == node->key)
            return node;
        else if (key < node->key)
            return getNode(node->left, key);
        else
            return getNode(node->right, key);
    }

    Node<K, V> *minmum(Node<K, V> *node)
    {
        if (node->left == nullptr)
            return node;

        return minmum(node->left);
    }

    Node<K, V> *removeMin(Node<K, V> *node)
    {
        if (node->left == nullptr)
        {
            Node<K, V> *rightNode = node->right;
            node->right = nullptr;
            size--;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    Node<K, V> *remove(Node<K, V> *node, K key)
    {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
        {
            node->left = remove(node->left, key);
            return node;
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
            return node;
        }
        else
        {
            if (node->left == nullptr)
            {
                Node<K, V> *rightNode = node->right;
                node->right = nullptr;
                size--;
                return rightNode;
            }

            if (node->right == nullptr)
            {
                Node<K, V> *leftNode = node->left;
                node->left = nullptr;
                size--;
                return leftNode;
            }

            Node<K, V> *successor = minmum(node->right);
            successor->right = removeMin(node->right);
            successor->left = node->left;

            node->left = node->right = nullptr;
            return successor;
        }
    }
};

#endif