
#ifndef DATASTRUCTURES_BST
#define DATASTRUCTURES_BST

#include <stack>
#include <queue>
#include <assert.h>
#include <iostream>

namespace BSTSETSPACE
{

    template <typename T>
    class Node
    {
    public:
        T e;
        Node<T> *left, *right;
        Node(T e) : e(e), left(nullptr), right(nullptr) {}
    };

    template <typename T>
    class BST
    {
    public:
        BST() : root(nullptr), size(0) {}

        int getSize() { return size; }
        bool isEmpty() { return size == 0; }

        void add(T e)
        {
            root = add(root, e);
        }

        bool contain(T e)
        {
            contain(root, e);
        }

        void preOrder()
        {
            preOrder(root);
        }

        void preOrderNR()
        {
            std::stack<Node<T> *> stack;
            stack.push(root);
            while (!stack.empty())
            {
                Node<T> *cur = stack.top();
                std::cout << cur->e << std::endl;
                stack.pop();
                if (cur->right != nullptr)
                {
                    stack.push(cur->right);
                }
                if (cur->left != nullptr)
                {
                    stack.push(cur->left);
                }
            }
        }

        void inOrder()
        {
            inOrder(root);
        }

        void postOrder()
        {
            postOrder(root);
        }

        void levelOrder()
        {
            std::queue<Node<T> *> *queue = new std::queue<Node<T> *>();
            queue->push(root);
            while (!queue->empty())
            {
                Node<T> *cur = queue->front();
                queue->pop();
                std::cout << cur->e << std::endl;
                if (cur->left != nullptr)
                {
                    queue->push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    queue->push(cur->right);
                }
            }
        }

        T minmum()
        {
            if (size == 0)
                assert("BST is empty");
            return minmum(root)->e;
        }

        T maxmum()
        {
            if (size == 0)
                assert("BST is empty");
            return maxmum(root)->e;
        }

        T removeMin()
        {
            T ret = minmum();
            root = removeMin(root);
            return ret;
        }

        T removeMax()
        {
            T ret = maxmum();
            root = removeMax(root);
            return ret;
        }

        void remove(T e)
        {
            root = remove(root, e);
        }

        std::string toString()
        {
            std::string res;
            generateBSTString(root, 0, res);
            return res;
        }

    private:
        Node<T> *root;
        int size;
        Node<T> *add(Node<T> *node, T e)
        {
            if (node == nullptr)
            {
                size++;
                return new Node<T>(e);
            }

            if (node->e > e)
                node->left = add(node->left, e);
            else if (node->e < e)
                node->right = add(node->right, e);
            return node;
        }

        bool contain(Node<T> *node, T e)
        {
            if (node == nullptr)
            {
                return false;
            }
            if (node->e == e)
                return true;
            else if (node->e < e)
            {
                return contain(node->left, e);
            }
            else
            {
                return contain(node->right, e);
            }
        }

        void preOrder(Node<T> *node)
        {
            // if (node == nullptr)
            //     return nullptr;

            if (node != nullptr)
            {
                std::cout << node->e << std::endl;
                preOrder(node->left);
                preOrder(node->right);
            }
        }

        void inOrder(Node<T> *node)
        {
            if (node == nullptr)
                return;
            inOrder(node->left);
            std::cout << node->e << std::endl;
            inOrder(node->right);
        }

        void postOrder(Node<T> *node)
        {
            if (node == nullptr)
                return;
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->e << std::endl;
        }

        void generateBSTString(Node<T> *node, int depth, std::string &res)
        {
            if (node == nullptr)
            {
                res += generateDepthString(depth) + "null\n";
                return;
            }
            res += generateDepthString(depth) + std::to_string(node->e) + "\n";
            generateBSTString(node->left, depth + 1, res);
            generateBSTString(node->right, depth + 1, res);
        }

        std::string generateDepthString(int depth)
        {
            std::string res;
            for (int i = 0; i < depth; i++)
            {
                res += "--";
            }
            return res;
        }

        Node<T> *minmum(Node<T> *node)
        {
            if (node->left == nullptr)
                return node;

            return minmum(node->left);
        }

        Node<T> *maxmum(Node<T> *node)
        {
            if (node->right == nullptr)
                return node;

            return maxmum(node->right);
        }

        Node<T> *removeMin(Node<T> *node)
        {
            if (node->left == nullptr)
            {
                Node<T> *rightNode = node->right;
                node->right = nullptr;
                size--;
                return rightNode;
            }

            node->left = removeMin(node->left);
            return node;
        }

        Node<T> *removeMax(Node<T> *node)
        {
            if (node->right == nullptr)
            {
                Node<T> *leftNode = node->left;
                node->left = nullptr;
                size--;
                return leftNode;
            }

            node->right = removeMax(node->right);
            return node;
        }

        Node<T> *remove(Node<T> *node, T e)
        {
            if (node == nullptr)
                return nullptr;

            if (e < node->e)
            {
                node->left = remove(node->left, e);
                return node;
            }
            else if (e > node->e)
            {
                node->right = remove(node->right, e);
                return node;
            }
            else
            {
                if (node->left == nullptr)
                {
                    Node<T> *rightNode = node->right;
                    node->right = nullptr;
                    size--;
                    return rightNode;
                }

                if (node->right == nullptr)
                {
                    Node<T> *leftNode = node->left;
                    node->left = nullptr;
                    size--;
                    return leftNode;
                }

                Node<T> *successor = minmum(node->right);
                successor->right = removeMin(node->right);
                successor->left = node->left;

                node->left = node->right = nullptr;
                return successor;
            }
        }
    };
}
#endif