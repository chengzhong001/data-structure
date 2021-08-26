template <typename T>
class Node
{
public:
    T e;
    Node<T> *left, right;
    Node(T e) : e(e), left(nullptr), right(right);
};

template <typename T>
class BST
{
public:
    BST() : root(nullptr), size(0);

    int size() { return size; }
    bool isEmpty() { return size == 0; }

    void add(T e)
    {
        root = add(root, e);
    }

private:
    Node<T> *root;
    int size;
    Node<T> *add(Node<T> *node, T e)
    {
        // if (node->e == e)
        // {
        //     return;
        // }
        // else if (node->e < e && node->left == nullptr)
        // {
        //     node->left = new Node<T>(e);
        // }
        // else if (node->e > e && node->right == nullptr)
        // {
        //     node->right = new Node<T>(e);
        // }
        if (node == nullptr)
        {
            size++;
            return new Node<T>;
        }

        if (node->e < e)
            node->left = add(node->left, e);
        else if (node->e > e)
            node->right = (node->right, e);
        return node;
    }

    bool contain(Node<T>* node, T e){
        if(node == nullptr){
            return false;
        }
        if(node->e == e) 
            return true;
        else if(node->e < e){
            return contain(node->left, e);
        }else{
            return contain(node->right, e);
        }
    }
};