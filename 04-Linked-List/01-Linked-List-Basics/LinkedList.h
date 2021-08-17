template<typename T>
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
