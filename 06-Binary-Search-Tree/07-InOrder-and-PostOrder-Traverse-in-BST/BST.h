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

    void inOrder(){
        inOrder(root);
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

    void inOrder(Node<T>* node){
        if(node == nullptr)
            return;
        preOrder(node->left);
        std::cout << node->e << std::endl;
        preOrder(node->right);
    }

    void generateBSTString(Node<T> *node, int depth, std::string& res)
    {
        if (node == nullptr)
        { 
           res += generateDepthString(depth) + "null\n";
           return;
        }
        res += generateDepthString(depth) + std::to_string(node->e) + "\n";
        generateBSTString(node->left, depth+1, res);
        generateBSTString(node->right, depth+1, res);
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
};