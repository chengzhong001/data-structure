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

private:
    Node<T> *root;
    int size;
};