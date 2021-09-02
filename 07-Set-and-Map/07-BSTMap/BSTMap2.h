
#ifndef BSTMAP_H
#define BSTMAP_H

#include <assert.h>
#include "Map.h"


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
        Node *node = getNode(root, key);
        return node == nullptr ? nullptr : &(node->value);
    }

    void set(K key, V newValue)
    {

        Node *node = getNode(root, key);
        if (node == nullptr)
            assert("key does not exist");
        node->value = newValue;
    }

    V *remove(K key)
    {
        Node *node = getNode(root, key);
        if (node == nullptr)
            return nullptr;
        root = remove(root, key);
        return &(node->value);
    }

private:
    struct Node
    {
        K key;
        V value;
        Node *left;
        Node *right;
        Node(K key, V value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };
    Node *root;
    int size;

    Node *add(Node *node, K key, V value)
    {
        if (node == nullptr)
        {
            size++;
            return new Node(key, value);
        }
        if (key < node->key)
            node->left = add(node->left, key, value);
        else if (key > node->key)
            node->right = add(node->right, key, value);
        else
            node->value = value;

        return node;
    }

    Node *getNode(Node *node, K key)
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

    Node *minmum(Node *node)
    {
        if (node->left == nullptr)
            return node;

        return minmum(node->left);
    }

    Node *removeMin(Node *node)
    {
        if (node->left == nullptr)
        {
            Node *rightNode = node->right;
            node->right = nullptr;
            size--;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    Node *remove(Node *node, K key)
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
                Node *rightNode = node->right;
                node->right = nullptr;
                size--;
                return rightNode;
            }

            if (node->right == nullptr)
            {
                Node *leftNode = node->left;
                node->left = nullptr;
                size--;
                return leftNode;
            }

            Node *successor = minmum(node->right);
            successor->right = removeMin(node->right);
            successor->left = node->left;

            node->left = node->right = nullptr;
            return successor;
        }
    }
};

#endif