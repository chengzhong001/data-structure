template <typename T>
class Node
{
public:
    T e;
    Node<T> *left, right;
    Node(T e) : e(e), left(nullptr), right(nullptr){}
};

template <typename T>
class BST
{
public:
    BST() : root(nullptr), size(0){}

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }

    void add(T e)
    {
        if (root == nullptr)
        {
            root = new Node<T>(e);
        }
        else
        {
            add(root, e);
        }
    }

private:
    Node<T> *root;
    int size;
    void add(Node<T> *node, T e)
    {
        if (node->e == e)
        {
            return;
        }
        else if (node->e < e && node->left == nullptr)
        {
            node->left = new Node<T>(e);
        }
        else if (node->e > e && node->right == nullptr)
        {
            node->right = new Node<T>(e);
        }
        if (node->e < e)
        {
            add(node->left, e);
        }
        else
        {
            add(node->right, e);
        }
    }
};