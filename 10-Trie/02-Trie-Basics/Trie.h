#include <map>
class Trie
{
private:
    class Node
    {
    private:
        bool isWord;
        std::map<char, Node> *next;

    public:
        Node(bool isWord) : isWord(isWord), next(new std::map<char, Node>()) {}
        Node() : isWord(false) {}
    };
    Node *root;
    int size;

public:
    Trie() : root(new Node()){};
    ~Trie() { delete root; };
};
